#include "Service.h"

void PrintString(string Text, int& ActiveString, bool LineFeed)
{
    cout << CSI << ActiveString << ";1H";
    cout << CSI << "2K";
    cout << Text;
    if (LineFeed)
    {
        cout << endl;
        ActiveString++;
    }
}

int GetKey()
{
#ifdef linux
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
#else
    return _getch();
#endif
}
