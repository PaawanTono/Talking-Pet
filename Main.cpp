#include <iostream>
#include <allegro.h>
#include <SFML/Audio.hpp>
#include <sstream>

using namespace std;


#define ScreenWidth 320
#define ScreenHeight 500


volatile long timer = 0;
void Increment() { timer++; }
END_OF_FUNCTION(Increment);


volatile int closeWindow = false;
void CloseButtonCallback() { closeWindow = true; }
END_OF_FUNCTION(CloseButtonCallBack);


//Initialized
void init()
{
	allegro_init();
	int depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, ScreenWidth, ScreenHeight, 0, 0);
	set_window_title("Talking Pets");
	install_keyboard();
	install_mouse();
	install_timer();
    
    show_mouse(screen);
    
	LOCK_FUNCTION(Increment);
	LOCK_VARIABLE(timer);
	
	LOCK_FUNCTION(CloseButtonCallback);
	LOCK_VARIABLE(closeWindow);
	
	install_int_ex(Increment, BPS_TO_TIMER(60));
	set_close_button_callback(CloseButtonCallback);
}

END_OF_FUNCTION(init);


int main()
{
	init();
	
	sf::SoundBufferRecorder recorder;
	sf::SoundBuffer buffer;
	const sf::SoundBuffer* buf;
	sf::Sound sound;
	
	int i;
	
	
	BITMAP *image[6];
	
	BITMAP *Buffer = create_bitmap(ScreenWidth, ScreenHeight);
	BITMAP *Bottom = load_bitmap("img/bottom bar.bmp", NULL);
	if(Bottom == NULL)
		{
		allegro_message("Invalid Graphics or Failed to load bitmaps. Please use a bmp formate of 24 bits or low");
		cout << "Invalid Graphics or Failed to load bitmaps. Please use a bmp formate of 24 bits or low";	
		}
	
	for(i = 0; i < 6; i++)
	{
		stringstream str;
		str << "img/Talking/c-" << i << ".bmp";
		image[i] = load_bitmap(str.str().c_str(), NULL);
		if(image[i] == NULL)
		{
		allegro_message("Invalid Graphics or Failed to load bitmaps. Please use a bmp formate of 24 bits or low");
		cout << "Invalid Graphics or Failed to load bitmaps. Please use a bmp formate of 24 bits or low";	
		}
	}
	image[6] = load_bitmap("img/listen.bmp", NULL);
	if(image[6] == NULL)
		{
		allegro_message("Invalid Graphics or Failed to load bitmaps. Please use a bmp formate of 24 bits or low");
		cout << "Invalid Graphics or Failed to load bitmaps. Please use a bmp formate of 24 bits or low";	
		}
	i = 6;
	
	
	//Window loop
	while(!closeWindow)
	{
		
		//Update loop
		while(timer > 0)
		{
			if(key[KEY_ESC]) //Esc key to exit
			{
				recorder.stop();
				sound.stop();
				closeWindow = true;
			}

		        
		    if(key[KEY_R]) //R key to Start Recording
				{
					sound.stop();
					recorder.start();
					
				} 
			else if(key[KEY_D])  //D key to start playing
				{
					recorder.stop();
					buffer = recorder.getBuffer();
					sound.setBuffer(buffer);
					sound.setPitch(1.5f);
					buf = sound.getBuffer();
					sound.play();
				}
		    else if(key[KEY_S]) //S to save to Recording
		    {
		    	buf->saveToFile("Save.wav");
			}
		    
		    if(sound.getStatus() == 0) // i set to 6 (listening bitmap) on recording
			{
				i = 6;
			}
			else //animate pet to speak while playing
			{
				i++;
				if(i >= 6)
				{
					i = 0;
				}
			}
		    
	    	timer--;
		}
		
		
		//draw
		masked_blit(image[(int)i], Buffer, 0, 0, 0, 0, ScreenWidth, ScreenHeight);
    	masked_blit(Bottom, Buffer, 0, 0, 0, 462, ScreenWidth, 38);
    	blit(Buffer, screen, 0, 0, 0, 0, ScreenWidth, ScreenHeight);
		rest(80);
	    clear_bitmap(Buffer);
	}
	
	
	//distroy
	for(int i = 0; i <7; i++)
	{
		destroy_bitmap(image[i]);
	}

	destroy_bitmap(Bottom);
	destroy_bitmap(Buffer);
	allegro_exit();
	
	return 0;
}

END_OF_MAIN()
