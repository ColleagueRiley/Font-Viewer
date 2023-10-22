#define RSGL_IMPLEMENTATION
#include "RSGL.h"

bool running=true;  int y=40;

int main(int args, char** argv){
      if (args <= 1) {
            printf("No input font file\n");
            return 1; 
      }

      int i;
      char* fontName = argv[1];

      for (i = 0; *fontName; fontName++)
            if (*fontName == '/')
                  i = (fontName - argv[1]) + 1;

      char win_name[60] = "RSGL-Font-Viewer | ";

      fontName = argv[1] + i;

      strcat(win_name, fontName);

      RSGL_window* win = RSGL_createWindow(win_name, RSGL_RECT(500, 500, 800, 280), 0);
      
      unsigned int font = RSGL_loadFont(argv[1]); 

      RSGL_setFont(font);

      char* texts[] = {fontName, "abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "0123456789.:,;(*!?')"};

      while(running){
            while(RSGL_window_checkEvent(win))
                  if (win->event.type == RGFW_quit) {
                        running = false; 
                        break;
                  }

            for (i = 0; i < sizeof(texts)/sizeof(char*); i++) 
                  RSGL_drawText(texts[i], 
                                                RSGL_CIRCLE(5, y + (i * 30), (i) ? 20 : 40), 
                                                RSGL_RGB(0, 0, 0));

            for (i = 10; i < 40; i += 10) 
                  RSGL_drawText("The quick brown fox jumps over the lazy dog.", 
                                                      RSGL_CIRCLE(5, 140 + ((i / 10) * (30 + (i / 4))), i), 
                                                      RSGL_RGB(0, 0, 0));
            
            RSGL_window_clear(win, RSGL_RGB(200, 200, 200));
      } 

      RSGL_window_close(win);
}