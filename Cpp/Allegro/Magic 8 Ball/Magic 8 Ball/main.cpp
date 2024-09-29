// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

using namespace std;

//GLOBAL VARIABLES
bool running=true;
bool visibleButton=true;

//PROTOTYPES
void game(ALLEGRO_EVENT_QUEUE*);
void ballAnswer(ALLEGRO_EVENT_QUEUE*, ALLEGRO_BITMAP*, ALLEGRO_BITMAP*);

//MAIN
int main(){
	//RANDOM GENERATOR
	srand(time(NULL));

	//VARIABLES

	//check of allegro is initialized correctly
	al_init();
	if(!al_init()){
		cout<<"\nERROR INITALIZING ALLEGRO\n";
		exit(1);
	}

	//---------- DISPLAY ----------
	ALLEGRO_DISPLAY* display=NULL;
	display=al_create_display(1280, 720);
	if(!display){
		cout<<"\nERROR CREATING THE DISPLAY\n";
		exit(1);
	}
	al_set_window_title(display, "Magic 8 Ball");
	al_init_image_addon();

	//---------- EVENT QUEUE ----------
	ALLEGRO_EVENT_QUEUE* queue=NULL;
	queue=al_create_event_queue();
	if(!queue){
		cout<<"\nERROR CREATING EVENT QUEUE\n";
		exit(1);
	}
	al_install_mouse();
	al_register_event_source(queue, al_get_mouse_event_source());
	if(!al_install_mouse()){
		cout<<"\nERROR INSTALLING MOUSE\n";
		exit(1);
	}
	al_install_keyboard();
	al_register_event_source(queue, al_get_keyboard_event_source());
	if(!al_install_keyboard()){
		cout<<"\nERROR INSTALLING KEYBOARD\n";
		exit(1);
	}

	//---------- TYPOGRAPHY ----------
	al_init_font_addon();
	al_init_ttf_addon();

	//---------- AUDIO ----------
	if(!al_install_audio()){
		cout<<"\nERROR INITIALIZING AUDIO SYSTEM\n";
		exit(1);
	}
	if(!al_init_acodec_addon()){
		cout<<"\nERROR INITIALIZING AUDIO CODECS\n";
		exit(1);
	}
	if(!al_reserve_samples(1)){
		cout<<"\nERROR RESERVING AUDIO CHANNEL CANALS\n";
		exit(1);
	}
	ALLEGRO_SAMPLE* song=NULL;
	song=al_load_sample("fairyTale.mp3");
	if(!song){
		cout<<"\nERROR LOADING SONG FILE\n";
		exit(1);
	}
	al_play_sample(song, .5, 0.0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);

	//---------- GEOMETRIC SHAPES ----------
	al_init_primitives_addon();

	//---------- GAME LOOP ----------
	while(running==true){
		game(queue);
	}

	return 0;
}

//IMPLEMENTATIONS
void game(ALLEGRO_EVENT_QUEUE* queue){
	visibleButton=true;
	//background
	al_clear_to_color(al_map_rgb(0, 0, 0));
	ALLEGRO_BITMAP* backgroundImage=NULL;
	backgroundImage=al_load_bitmap("background.png");
	if(!backgroundImage){
		cout<<"\nERROR LOADING MENU BACKGROUND IMAGE\n";
		exit(1);
	}
	al_draw_bitmap(backgroundImage, 0, 0, 0);

	//help description
	ALLEGRO_FONT* titleFontShadow=NULL;
	titleFontShadow=al_load_ttf_font("daFont.ttf", 21, 0);
	if(!titleFontShadow){
		cout<<"\nERROR LOADING TITLE FONT\n";
		exit(1);
	}
	ALLEGRO_FONT* titleFont=NULL;
	titleFont=al_load_ttf_font("daFont.ttf", 21, 0);
	if(!titleFont){
		cout<<"\nERROR LOADING TITLE FONT\n";
		exit(1);
	}
	al_draw_text(titleFontShadow, al_map_rgb(77, 74, 49), 642, 42, ALLEGRO_ALIGN_CENTER, "Concentrate on your question and click the button when you are ready");
	al_draw_text(titleFont, al_map_rgb(174, 167, 106), 640, 40, ALLEGRO_ALIGN_CENTER, "Concentrate on your question and click the button when you are ready");

	//eight plain ball
	ALLEGRO_BITMAP* eightBall=NULL;
	eightBall=al_load_bitmap("eight-ball.png");
	if(!eightBall){
		cout<<"\nERROR LOADING EIGHT BALL IMAGE\n";
		exit(1);
	}
	float width_image1=al_get_bitmap_width(eightBall);
	float high_image1=al_get_bitmap_height(eightBall);
	float new_image_width1=width_image1*1.5;
	float new_image_high1=high_image1*1.5;
	al_draw_scaled_bitmap(eightBall, 0, 0, width_image1, high_image1, 165, 100, new_image_width1, new_image_high1, 0);

	//light ask button
	ALLEGRO_BITMAP* lightButton=NULL;
	lightButton=al_load_bitmap("light-button.png");
	if(!lightButton){
		cout<<"\nERROR LOADING LIGHT BUTTON IMAGE\n";
		exit(1);
	}
	float width_image2=al_get_bitmap_width(lightButton);
	float high_image2=al_get_bitmap_height(lightButton);

	//obscure ask button
	ALLEGRO_BITMAP* obscureButton=NULL;
	obscureButton=al_load_bitmap("obscure-button.png");
	if(!obscureButton){
		cout<<"\nERROR LOADING OBSCURE BUTTON IMAGE\n";
		exit(1);
	}
	float width_image3=al_get_bitmap_width(obscureButton);
	float high_image3=al_get_bitmap_height(obscureButton);

	//quit button
	ALLEGRO_FONT* buttonFont=NULL;
	buttonFont=al_load_ttf_font("daFont.ttf", 20, 0);
	if(!buttonFont){
		cout<<"\nERROR LOADING BUTTON FONT\n";
		exit(1);
	}
	ALLEGRO_COLOR buttonColor=al_map_rgba(174, 167, 106, 0.2);
	float buttonCornerRadius=5;
	al_draw_rounded_rectangle(25, 630, 150, 690, buttonCornerRadius, buttonCornerRadius, buttonColor, 4);
	al_draw_text(buttonFont, al_map_rgb(255, 255, 255), 85, 632, ALLEGRO_ALIGN_CENTER, "Quit");

	//inside-queue variables
	bool done=false;

	//button functionality
	while(!done){
		ALLEGRO_EVENT event;
		al_wait_for_event(queue, &event);

		int mouseX=event.mouse.x;
		int mouseY=event.mouse.y;

		//for changing the ask button color if selected
		if(visibleButton==true){
			if(mouseX>=562 && mouseX<=752){
				if(mouseY>=565 && mouseY<=627){
					al_draw_scaled_bitmap(obscureButton, 0, 0, width_image3, high_image3, 325, 270, width_image3, high_image3, 0);
				}
			}else{
				al_draw_scaled_bitmap(lightButton, 0, 0, width_image2, high_image2, 325, 270, width_image2, high_image2, 0);
			}
		}

		//for clicking the ask button
		if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
			if(mouseX>=562 && mouseX<=752){
				if(mouseY>=565 && mouseY<=627){
					visibleButton=false;
					ballAnswer(queue, backgroundImage, eightBall);
				}
			}
		}

		//for clicking the quit button
		if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
			if(mouseX>=25 && mouseX<=150){
				if(mouseY>=630 && mouseY<=690){
					exit(1);
				}
			}
		}

		al_flip_display();
	}
}

void ballAnswer(ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_BITMAP* backgroundImage, ALLEGRO_BITMAP* eightBall){
	int randomOption=0, movementType=0;
	float width_image1=al_get_bitmap_width(eightBall);
	float high_image1=al_get_bitmap_height(eightBall);
	float new_image_width1=width_image1*1.5;
	float new_image_high1=high_image1*1.5;

	ALLEGRO_FONT* buttonFont=NULL;
	buttonFont=al_load_ttf_font("daFont.ttf", 20, 0);
	if(!buttonFont){
		cout<<"\nERROR LOADING BUTTON FONT\n";
		exit(1);
	}
	ALLEGRO_COLOR buttonColor=al_map_rgba(174, 167, 106, 0.2);
	float buttonCornerRadius=5;


	//bad answer balls
	ALLEGRO_BITMAP* badAnswer1=NULL; //1
	badAnswer1=al_load_bitmap("badAns1.png");
	if(!badAnswer1){
		cout<<"\nERROR LOADING BAD ANSWER 1 IMAGE\n";
		exit(1);
	}
	ALLEGRO_BITMAP* badAnswer2=NULL; //2
	badAnswer2=al_load_bitmap("badAns2.png");
	if(!badAnswer2){
		cout<<"\nERROR LOADING BAD ANSWER 2 IMAGE\n";
		exit(1);
	}
	ALLEGRO_BITMAP* badAnswer3=NULL; //3
	badAnswer3=al_load_bitmap("badAns3.png");
	if(!badAnswer3){
		cout<<"\nERROR LOADING BAD ANSWER 3 IMAGE\n";
		exit(1);
	}
	ALLEGRO_BITMAP* badAnswer4=NULL; //4
	badAnswer4=al_load_bitmap("badAns4.png");
	if(!badAnswer4){
		cout<<"\nERROR LOADING BAD ANSWER 4 IMAGE\n";
		exit(1);
	}
	ALLEGRO_BITMAP* badAnswer5=NULL; //5
	badAnswer5=al_load_bitmap("badAns5.png");
	if(!badAnswer5){
		cout<<"\nERROR LOADING BAD ANSWER 5 IMAGE\n";
		exit(1);
	}

	//medium answer balls
	ALLEGRO_BITMAP* medAnswer1=NULL; //1
	medAnswer1=al_load_bitmap("mediumAns1.png");
	if(!medAnswer1){
		cout<<"\nERROR LOADING MEDIUM ANSWER 1 IMAGE\n";
		exit(1);
	}
	ALLEGRO_BITMAP* medAnswer2=NULL; //2
	medAnswer2=al_load_bitmap("mediumAns2.png");
	if(!medAnswer2){
		cout<<"\nERROR LOADING MEDIUM ANSWER 2 IMAGE\n";
		exit(1);
	}
	ALLEGRO_BITMAP* medAnswer3=NULL; //3
	medAnswer3=al_load_bitmap("mediumAns3.png");
	if(!medAnswer3){
		cout<<"\nERROR LOADING MEDIUM ANSWER 3 IMAGE\n";
		exit(1);
	}
	ALLEGRO_BITMAP* medAnswer4=NULL; //4
	medAnswer4=al_load_bitmap("mediumAns4.png");
	if(!medAnswer4){
		cout<<"\nERROR LOADING MEDIUM ANSWER 4 IMAGE\n";
		exit(1);
	}
	ALLEGRO_BITMAP* medAnswer5=NULL; //5
	medAnswer5=al_load_bitmap("mediumAns5.png");
	if(!medAnswer5){
		cout<<"\nERROR LOADING MEDIUM ANSWER 5 IMAGE\n";
		exit(1);
	}

	//good answer balls
	ALLEGRO_BITMAP* goodAns1=NULL; //1
	goodAns1=al_load_bitmap("goodAns1.png");
	if(!goodAns1){
		cout<<"\nERROR LOADING GOOD ANSWER 1 IMAGE\n";
		exit(1);
	}
	ALLEGRO_BITMAP* goodAns2=NULL; //2
	goodAns2=al_load_bitmap("goodAns2.png");
	if(!goodAns2){
		cout<<"\nERROR LOADING GOOD ANSWER 2 IMAGE\n";
		exit(1);
	}
	ALLEGRO_BITMAP* goodAns3=NULL; //3
	goodAns3=al_load_bitmap("goodAns3.png");
	if(!goodAns3){
		cout<<"\nERROR LOADING GOOD ANSWER 3 IMAGE\n";
		exit(1);
	}
	ALLEGRO_BITMAP* goodAns4=NULL; //4
	goodAns4=al_load_bitmap("goodAns4.png");
	if(!goodAns4){
		cout<<"\nERROR LOADING GOOD ANSWER 4 IMAGE\n";
		exit(1);
	}
	ALLEGRO_BITMAP* goodAns5=NULL; //5
	goodAns5=al_load_bitmap("goodAns5.png");
	if(!goodAns5){
		cout<<"\nERROR LOADING GOOD ANSWER 5 IMAGE\n";
		exit(1);
	}
	ALLEGRO_BITMAP* goodAns6=NULL; //6
	goodAns6=al_load_bitmap("goodAns6.png");
	if(!goodAns6){
		cout<<"\nERROR LOADING GOOD ANSWER 6 IMAGE\n";
		exit(1);
	}
	ALLEGRO_BITMAP* goodAns7=NULL; //7
	goodAns7=al_load_bitmap("goodAns7.png");
	if(!goodAns7){
		cout<<"\nERROR LOADING GOOD ANSWER 7 IMAGE\n";
		exit(1);
	}
	ALLEGRO_BITMAP* goodAns8=NULL; //8
	goodAns8=al_load_bitmap("goodAns8.png");
	if(!goodAns8){
		cout<<"\nERROR LOADING GOOD ANSWER 8 IMAGE\n";
		exit(1);
	}
	ALLEGRO_BITMAP* goodAns9=NULL; //9
	goodAns9=al_load_bitmap("goodAns9.png");
	if(!goodAns9){
		cout<<"\nERROR LOADING GOOD ANSWER 9 IMAGE\n";
		exit(1);
	}
	ALLEGRO_BITMAP* goodAns10=NULL; //10
	goodAns10=al_load_bitmap("goodAns10.png");
	if(!goodAns10){
		cout<<"\nERROR LOADING GOOD ANSWER 10 IMAGE\n";
		exit(1);
	}

	float width_image2=al_get_bitmap_width(badAnswer1);
	float high_image2=al_get_bitmap_height(badAnswer1);
	float new_image_width2=width_image2*1.5;
	float new_image_high2=high_image2*1.5;
	
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(backgroundImage, 0, 0, 0);
	
	for(int i=0; i<9; i++){
		movementType=rand()%7;
		switch(movementType){
		case 0:
			//north movement
			al_draw_scaled_bitmap(eightBall, 0, 0, width_image1, high_image1, 165, 50, new_image_width1, new_image_high1, 0);
			Sleep(100);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(backgroundImage, 0, 0, 0);
			//normal movement
			al_draw_scaled_bitmap(eightBall, 0, 0, width_image1, high_image1, 165, 100, new_image_width1, new_image_high1, 0);
			Sleep(100);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(backgroundImage, 0, 0, 0);
			break;
		case 1:
			//northeast movement
			al_draw_scaled_bitmap(eightBall, 0, 0, width_image1, high_image1, 190, 75, new_image_width1, new_image_high1, 0);
			Sleep(100);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(backgroundImage, 0, 0, 0);
			//normal movement
			al_draw_scaled_bitmap(eightBall, 0, 0, width_image1, high_image1, 165, 100, new_image_width1, new_image_high1, 0);
			Sleep(100);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(backgroundImage, 0, 0, 0);
			break;
		case 2:
			//east movement
			al_draw_scaled_bitmap(eightBall, 0, 0, width_image1, high_image1, 215, 100, new_image_width1, new_image_high1, 0);
			Sleep(100);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(backgroundImage, 0, 0, 0);
			//normal movement
			al_draw_scaled_bitmap(eightBall, 0, 0, width_image1, high_image1, 165, 100, new_image_width1, new_image_high1, 0);
			Sleep(100);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(backgroundImage, 0, 0, 0);
			break;
		case 3:
			//southeast movement
			al_draw_scaled_bitmap(eightBall, 0, 0, width_image1, high_image1, 215, 125, new_image_width1, new_image_high1, 0);
			Sleep(100);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(backgroundImage, 0, 0, 0);
			//normal movement
			al_draw_scaled_bitmap(eightBall, 0, 0, width_image1, high_image1, 165, 100, new_image_width1, new_image_high1, 0);
			Sleep(100);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(backgroundImage, 0, 0, 0);
			break;
		case 4:
			//south movement
			al_draw_scaled_bitmap(eightBall, 0, 0, width_image1, high_image1, 165, 150, new_image_width1, new_image_high1, 0);
			Sleep(100);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(backgroundImage, 0, 0, 0);
			//normal movement
			al_draw_scaled_bitmap(eightBall, 0, 0, width_image1, high_image1, 165, 100, new_image_width1, new_image_high1, 0);
			Sleep(100);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(backgroundImage, 0, 0, 0);
			break;
		case 5:
			//southwest movement
			al_draw_scaled_bitmap(eightBall, 0, 0, width_image1, high_image1, 140, 125, new_image_width1, new_image_high1, 0);
			Sleep(100);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(backgroundImage, 0, 0, 0);
			//normal movement
			al_draw_scaled_bitmap(eightBall, 0, 0, width_image1, high_image1, 165, 100, new_image_width1, new_image_high1, 0);
			Sleep(100);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(backgroundImage, 0, 0, 0);
			break;
		case 6:
			//west movement
			al_draw_scaled_bitmap(eightBall, 0, 0, width_image1, high_image1, 115, 100, new_image_width1, new_image_high1, 0);
			Sleep(100);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(backgroundImage, 0, 0, 0);
			//normal movement
			al_draw_scaled_bitmap(eightBall, 0, 0, width_image1, high_image1, 165, 100, new_image_width1, new_image_high1, 0);
			Sleep(100);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(backgroundImage, 0, 0, 0);
			break;
		case 7:
			//northwest movement 
			al_draw_scaled_bitmap(eightBall, 0, 0, width_image1, high_image1, 140, 75, new_image_width1, new_image_high1, 0);
			Sleep(100);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(backgroundImage, 0, 0, 0);
			//normal movement
			al_draw_scaled_bitmap(eightBall, 0, 0, width_image1, high_image1, 165, 100, new_image_width1, new_image_high1, 0);
			Sleep(100);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(backgroundImage, 0, 0, 0);
			break;
		}
	}
	al_draw_scaled_bitmap(eightBall, 0, 0, width_image1, high_image1, 165, 100, new_image_width1, new_image_high1, 0);
	Sleep(100);
	al_flip_display();
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(backgroundImage, 0, 0, 0);
	randomOption=rand()%19;
	switch(randomOption){
		case 0:
			al_draw_scaled_bitmap(badAnswer1, 0, 0, width_image2, high_image2, 165, 100, new_image_width2, new_image_high2, 0);
			al_flip_display();
			break;
		case 1:
			al_draw_scaled_bitmap(badAnswer2, 0, 0, width_image2, high_image2, 165, 100, new_image_width2, new_image_high2, 0);
			al_flip_display();
			break;
		case 2:
			al_draw_scaled_bitmap(badAnswer3, 0, 0, width_image2, high_image2, 165, 100, new_image_width2, new_image_high2, 0);
			al_flip_display();
			break;
		case 3:
			al_draw_scaled_bitmap(badAnswer4, 0, 0, width_image2, high_image2, 165, 100, new_image_width2, new_image_high2, 0);
			al_flip_display();
			break;
		case 4:
			al_draw_scaled_bitmap(badAnswer5, 0, 0, width_image2, high_image2, 165, 100, new_image_width2, new_image_high2, 0);
			al_flip_display();
			break;
		case 5:
			al_draw_scaled_bitmap(medAnswer1, 0, 0, width_image2, high_image2, 165, 100, new_image_width2, new_image_high2, 0);
			al_flip_display();
			break;
		case 6:
			al_draw_scaled_bitmap(medAnswer2, 0, 0, width_image2, high_image2, 165, 100, new_image_width2, new_image_high2, 0);
			al_flip_display();
			break;
		case 7:
			al_draw_scaled_bitmap(medAnswer3, 0, 0, width_image2, high_image2, 165, 100, new_image_width2, new_image_high2, 0);
			al_flip_display();
			break;
		case 8:
			al_draw_scaled_bitmap(medAnswer4, 0, 0, width_image2, high_image2, 165, 100, new_image_width2, new_image_high2, 0);
			al_flip_display();
			break;
		case 9:
			al_draw_scaled_bitmap(medAnswer5, 0, 0, width_image2, high_image2, 165, 100, new_image_width2, new_image_high2, 0);
			al_flip_display();
			break;
		case 10:
			al_draw_scaled_bitmap(goodAns1, 0, 0, width_image2, high_image2, 165, 100, new_image_width2, new_image_high2, 0);
			al_flip_display();
			break;
		case 11:
			al_draw_scaled_bitmap(goodAns2, 0, 0, width_image2, high_image2, 165, 100, new_image_width2, new_image_high2, 0);
			al_flip_display();
			break;
		case 12:
			al_draw_scaled_bitmap(goodAns3, 0, 0, width_image2, high_image2, 165, 100, new_image_width2, new_image_high2, 0);
			al_flip_display();
			break;
		case 13:
			al_draw_scaled_bitmap(goodAns4, 0, 0, width_image2, high_image2, 165, 100, new_image_width2, new_image_high2, 0);
			al_flip_display();
			break;
		case 14:
			al_draw_scaled_bitmap(goodAns5, 0, 0, width_image2, high_image2, 165, 100, new_image_width2, new_image_high2, 0);
			al_flip_display();
			break;
		case 15:
			al_draw_scaled_bitmap(goodAns6, 0, 0, width_image2, high_image2, 165, 100, new_image_width2, new_image_high2, 0);
			al_flip_display();
			break;
		case 16:
			al_draw_scaled_bitmap(goodAns7, 0, 0, width_image2, high_image2, 165, 100, new_image_width2, new_image_high2, 0);
			al_flip_display();
			break;
		case 17:
			al_draw_scaled_bitmap(goodAns8, 0, 0, width_image2, high_image2, 165, 100, new_image_width2, new_image_high2, 0);
			al_flip_display();
			break;
		case 18:
			al_draw_scaled_bitmap(goodAns9, 0, 0, width_image2, high_image2, 165, 100, new_image_width2, new_image_high2, 0);
			al_flip_display();
			break;
		case 19:
			al_draw_scaled_bitmap(goodAns10, 0, 0, width_image2, high_image2, 165, 100, new_image_width2, new_image_high2, 0);
			al_flip_display();
			break;
	}

	//quit button
	al_draw_rounded_rectangle(25, 630, 150, 690, buttonCornerRadius, buttonCornerRadius, buttonColor, 4);
	al_draw_text(buttonFont, al_map_rgb(255, 255, 255), 85, 632, ALLEGRO_ALIGN_CENTER, "Quit");
	al_flip_display();

	//Ask again button
	al_draw_rounded_rectangle(1090, 630, 1255, 690, buttonCornerRadius, buttonCornerRadius, buttonColor, 4);
	al_draw_text(buttonFont, al_map_rgb(255, 255, 255), 1170, 632, ALLEGRO_ALIGN_CENTER, "Ask again");
	al_flip_display();

	//inside-queue variables
	bool done=false;

	//button functionality
	while(!done){
		ALLEGRO_EVENT event;
		al_wait_for_event(queue, &event);

		int mouseX=event.mouse.x;
		int mouseY=event.mouse.y;

		//for clicking the quit button
		if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
			if(mouseX>=25 && mouseX<=150){
				if(mouseY>=630 && mouseY<=690){
					exit(1);
				}
			}
		}

		//for clicking the ask again button
		if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
			if(mouseX>=1090 && mouseX<=1255){
				if(mouseY>=630 && mouseY<=690){
					game(queue);
				}
			}
		}

		al_flip_display();
	}
}