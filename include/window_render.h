
int create_window_render(SDL_Window ** window, SDL_Renderer ** renderer,int window_width, int window_height);

int init_window_render(global_structure_t ** global_structure);

void destroy_window_render(SDL_Window ** window, SDL_Renderer ** renderer);

void limit_fps(unsigned int limit,int fps_limit);
