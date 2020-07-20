#include <termios.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

void sig_winch(int signo)
{
    struct winsize size;
    ioctl(fileno(stdout), TIOCGWINSZ, (char *)&size);
    resizeterm(size.ws_row, size.ws_col);
}

int main()
{
    initscr();
    int i;
    WINDOW *wnd;
    WINDOW *subwnd;
    FILE *file;
    char *file_name = "text.txt";
    char load_string_out[250];
    char load_string_in[250];
    char load_string_in1[250] = {0};
    signal(SIGWINCH, sig_winch);
    cbreak();
    curs_set(0);
    file = fopen(file_name, "r+w");
    start_color();
    refresh();
    init_pair(1, COLOR_YELLOW, COLOR_BLUE);
    wnd = newwin(20, 70, 1, 1);
    wbkgd(wnd, COLOR_PAIR(1));
    while (fgets(load_string_out, 250, file) != NULL)
    {
        wprintw(wnd, "%s\n", load_string_out);
    } 
    wgetstr(wnd, load_string_in);   
    wrefresh(wnd);
    load_string_in[strlen(load_string_in)] = '\n';
    fputs(load_string_in, file);
    // wrefresh(wnd);
    delwin(wnd);
    refresh();
    getch();
    fclose(file);                               
    endwin();
    exit(EXIT_SUCCESS);                                                                                                                                                                                                                                               
    return 0;                               
}                           
