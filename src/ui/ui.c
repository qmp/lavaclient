#include <ncurses.h>
#include <string.h>
#include <signal.h>
#include "ui.h"

#define MAILBOX 0
#define READ    1
#define WRITE   2

#define ENTER 10
#define ESCAPE 27

#define MENU_HEIGHT 1

int lava_state = 0;

/*Windows for mailbox*/
WINDOW* mainwin;
WINDOW* menuwin;
WINDOW* statuswin;
/*Windows for readmail*/
WINDOW* header;
WINDOW* footer;
WINDOW* readmail;
/*Windows for writemail*/
WINDOW* writemail;

int main()
{//char[] title = "blablabla";
    /*Start curses mode*/
	init_curses();
    /*Define resize signal method*/
	signal(SIGWINCH, do_resize);

    refresh();
/*
    mvwprintw(menuwin,0,1, "| Menu |");
    mvwprintw(mainwin,0,1, "| Mails |");
    mvwprintw(statuswin,0,1, "| Status |");

    wrefresh(statuswin);
    wrefresh(mainwin);
    wrefresh(menuwin);
//    mvprintw(row/2,(col-strlen(title))/2,"%s",title);
//    refresh();          // Print it on to the real screen
*/
  //  mvprintw(1,1,"%s",menu_test);
  //  mvprintw(7,5,"%s",title);
  //  refresh();
  int key;
    do {
        int selected_item;
        //WINDOW **menu_items;
        key=getch();
        //werase(messagebar);
        //wrefresh(messagebar);
        if (key==KEY_F(1)) {
        //    menu_items=draw_menu(0);
        //    selected_item=scroll_menu(menu_items,8,0);
        //    delete_menu(menu_items,9);
        //    if (selected_item<0)
        //        wprintw(messagebar,"You haven't selected any item.");
        //    else
        //        wprintw(messagebar,
        //          "You have selected menu item %d.",selected_item+1);
        //    touchwin(stdscr);
        //    refresh();
        } else if (key==KEY_F(2)) {
        //    menu_items=draw_menu(20);
        //    selected_item=scroll_menu(menu_items,8,20);
        //    delete_menu(menu_items,9);
        //    if (selected_item<0)
        //        wprintw(messagebar,"You haven't selected any item.");
        //    else
        //        wprintw(messagebar,
        //          "You have selected menu item %d.",selected_item+1);
        //    touchwin(stdscr);
        //    refresh();
        }
    } while (key!=ESCAPE);
	/* End curses mode*/
	end_curses();

    return 0;
}

void do_resize(int sig)
{
    endwin();
    refresh();
    update_ui();
}

int init_curses()
{
	/*Start curses mode*/
	initscr();
    /*Color initialization*/
    start_color();
    init_pair(1,COLOR_YELLOW,COLOR_RED);
    init_pair(2,COLOR_RED,COLOR_YELLOW);

    curs_set(0);

	cbreak();
	return 0;
}

int end_curses()
{
	/*End curses mode*/
	endwin();
	return 0;
}

void update_ui()
{
//   del_window(mainwin);
//    del_window(menuwin);
//    del_window(statuswin);
//    del_windows(header);
//    del_windows(footer);
//    del_windows(readmail);
//    del_windows(writemail);
//    del_windows(mainwin);
    draw_windows();
}

void draw_windows()
{
    switch(lava_state)
    {
        case MAILBOX:
            menuwin = create_menu_window(MENU_HEIGHT, COLS, 0, 0);
            mainwin = create_window(LINES-(2*MENU_HEIGHT),COLS,MENU_HEIGHT,0);
            statuswin = create_status_window(MENU_HEIGHT,COLS,LINES-MENU_HEIGHT,0);
        break;

        case READ:

        break;

        case WRITE:

        break;
    }
}
WINDOW* create_menu_window(int height, int width, int starty, int startx)
{
    //Create the window
    WINDOW* localwin = newwin(height, width, starty, startx);

    /*Draw menu*/
    wbkgd(localwin,COLOR_PAIR(1));

    //wattron(localwin,COLOR_PAIR(1));
    waddstr(localwin,"Accounts");
    wmove(localwin,0,20);
    waddstr(localwin,"Delete");
    wmove(localwin,0,40);
    waddstr(localwin,"Folders");
    //wattroff(localwin,COLOR_PAIR(1));

    //Refresh the window
    wrefresh(localwin);

    return localwin;
}

WINDOW* create_status_window(int height, int width, int starty, int startx)
{
    //Create the window
    WINDOW* localwin = newwin(height, width, starty, startx);
    //Refresh the window
    wrefresh(localwin);

    return localwin;
}

WINDOW* create_window(int height, int width, int starty, int startx)
{
    //Create the window
    WINDOW* localwin = newwin(height, width, starty, startx);
    //Make a box around the window
    box(localwin,0,0);
    //Refresh the window
    wrefresh(localwin);

    return localwin;
}

void del_window(WINDOW* win)
{

    wborder(win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	/* The parameters taken are
	 * 1. win: the window on which to operate
	 * 2. ls: character to be used for the left side of the window
	 * 3. rs: character to be used for the right side of the window
	 * 4. ts: character to be used for the top side of the window
	 * 5. bs: character to be used for the bottom side of the window
	 * 6. tl: character to be used for the top left corner of the window
	 * 7. tr: character to be used for the top right corner of the window
	 * 8. bl: character to be used for the bottom left corner of the window
	 * 9. br: character to be used for the bottom right corner of the window
	 */
	wrefresh(win);
	delwin(win);
}

