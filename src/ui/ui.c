#include <ncurses.h>
#include <stdlib.h>

#define ENTER 10
#define ESCAPE 27

int main()
{
    int key;
    WINDOW *mainmenubar;
	
    init_curses();

    bkgd(COLOR_PAIR(1));

    mainmenubar=subwin(stdscr,1,80,0,0);
    //messagebar=subwin(stdscr,1,79,23,1);
    draw_mainmenubar(mainmenubar);
    move(2,1);

    refresh();
    
    do{
	key=getch();
	
    }while(key!=ESCAPE);
    delwin(mainmenubar);
    endwin();
    return 0;
}

int init_curses()
{
    initscr();          /* Start curses mode          */
    start_color();      /* Color ? */

    /*Aucune idée, c'est juste un teste*/
    init_pair(1,COLOR_RED,COLOR_YELLOW);
    init_pair(2,COLOR_YELLOW,COLOR_RED);
    init_pair(3,COLOR_GREEN,COLOR_WHITE);

    curs_set(0);        /*Curseur invisible*/
    noecho();           /*N'affiche pas, ou controle l'affichage des entrées clavier*/
    keypad(stdscr, TRUE); /*Active l'usage des touches de fonction pour la fenêtre stdscr*/
	
    return 0;
}

int draw_mainmenubar(WINDOW *mainmenubar)
{
    wbkgd(mainmenubar, COLOR_PAIR(2));
    waddstr(mainmenubar, "NEW MAIL");
    wattron(mainmenubar, COLOR_PAIR(3));
    waddstr(mainmenubar, "(F1)");
    wattroff(mainmenubar, COLOR_PAIR(3));
    wmove(mainmenubar, 0, 20);

    return 0;
}

/*
WINDOW **draw_menu(int start_col)
{

}
*/
