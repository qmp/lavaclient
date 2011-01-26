/* User interface, list mails, display operations in progress, etc
 */

void do_resize(int sig);
int init_curses();
int end_curses();
void update_ui();
void draw_windows();
WINDOW* create_window(int height, int width, int starty, int startx);
WINDOW* create_menu_window(int height, int width, int starty, int startx);
WINDOW* create_status_window(int height, int width, int starty, int startx);
void del_window(WINDOW* win);
