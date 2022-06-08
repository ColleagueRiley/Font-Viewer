#include <RSGL/RSGL.hpp>

bool running=true;  int y=40;

int main(int args, char** argv){
      std::string font, fontName; 
      if (args > 1){ font = argv[1]; fontName=font; }
      int l = fontName.find_last_of('/')+1;
      fontName.replace(fontName.begin(),fontName.begin()+l,"");
      l = fontName.find_last_of('.');
      fontName.replace(fontName.begin()+l,fontName.end(),"");
      std::vector<std::string> texts={fontName,"abcdefghijklmnopqrstuvwxyz","ABCDEFGHIJKLMNOPQRSTUVWXYZ","0123456789.:,;(*!?')"};
      RSGL::window win("RSGL-Font-Viewer | "+fontName,{500,500,800,280},{255,255,255});

      while(running){
            win.checkEvents();
            if (win.event.type == RSGL::quit) running = false; 
            for (int i=0; i < texts.size(); i++) RSGL::drawText(texts.at(i),{5,y+(i*30), (!i) ? 40 : 20},font,{0,0,0});
            for (int i=10; i < 40; i+=10) RSGL::drawText("The quick brown fox jumps over the lazy dog.",{5,140+((i/10)*(30+(i/4))),i},font,{0,0,0});
            win.clear();
      } win.close();
}