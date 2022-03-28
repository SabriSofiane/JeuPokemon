
int create_window_render(SDL_Window ** window, SDL_Renderer ** renderer,int window_width, int window_height);

int init_window_render(motor_t ** motor);

void destroy_window_render(SDL_Window ** window, SDL_Renderer ** renderer);

void limit_fps(unsigned int limit,int fps_limit);
