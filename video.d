version(curses) {
	extern struct WINDOW;
	extern (C) private WINDOW* initscr();
	extern (C) private WINDOW* newwin(int, int, int, int);
	extern (C) private int keypad(WINDOW*, bool);
	extern (C) private int raw();
	extern (C) private int noecho();
	extern (C) private int curs_set(int);
	extern (C) private int delwin(WINDOW*);
	extern (C) private int wrefresh(WINDOW*);
	extern (C) private int wgetch(WINDOW*);
	extern (C) private int waddch(WINDOW*, char);
	extern (C) private int mvwaddch(WINDOW*, int, int, char);
	extern (C) private int endwin();
	extern (C) private int wcolor_set(WINDOW*, int);
	extern (C) private int init_pair(int, int, int);
	extern (C) private int start_color();
	extern (C) private int attron(int);
	extern (C) private int attroff(int);

	private int COLOR_PAIR(int n) {
		return n << 8;
	}

	class Window {
		private WINDOW *w;

		int width;
		int height;
		int x;
		int y;

		private this() {

		}

		private void postinit() {
			keypad(this.w, true);
		}

		this(int w, int h, int x, int y) {
			this.w = newwin(h, w, x, y);
			this.width  = w;
			this.height = h;
			this.x = x;
			this.y = y;
			this.postinit();
		}

		~this() {
			delwin(this.w);
		}

		int getChar() {
			return wgetch(this.w);
		}

		void addChar(char c) {
			attron(COLOR_PAIR(1));
			waddch(this.w, c);
			attroff(COLOR_PAIR(1));
		}

		void addChar(int x, int y, char c) {
			mvwaddch(this.w, y, x, c);
		}

		void refresh() {
			wrefresh(this.w);
		}
	}

	class Screen : Window {
		this() {
			this.w = initscr();
			this.postinit();
			raw();
			noecho();
			curs_set(0);
			start_color();
			init_pair(1, 1, 0);
			//wcolor_set(this.w, 1);
		}

		~this() {
			endwin();
		}

		void dod() {
			init_pair(1, 2, 0);
		}
	}
}