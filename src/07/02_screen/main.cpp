#include <iostream>
#include <vector>
#include <string>

class Screen
{
    friend class Window_mgr;
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c){ }

    char get() const                            // implicitly inline function
    {
        return contents[cursor];
    }

    inline char get(pos ht, pos wd) const;      // explicitly inline
    Screen &move(pos r, pos c);                 // can be made inline later

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;                               // return this object as an lvalue
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

class Window_mgr
{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
    ScreenIndex addScreen(const Screen&);
private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen& screen)
{
    screens.push_back(screen);
    return screens.size() - 1;
}

int main()
{
    Screen::pos ht = 24, wd = 80;
    Screen scr(ht, wd, 'r');
    Screen *p = &scr;
    char c = scr.get();
    std::cout << c << std::endl;
    c = p->get();
    std::cout << c << std::endl;

    return 0;
}