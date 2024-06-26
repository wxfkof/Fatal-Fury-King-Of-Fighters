#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"
#include "SDL\include\SDL.h"
#include "ModuleMusic.h"
#include "Application.h"
#include "p2Point.h"
#include "ModuleFFIntro.h"
#include "ModuleFFIntro2.h"
#include "ModuleUI.h"
#include "ModuleWelcomeScreen.h"
#include "ModuleControls.h"

ModuleFFIntro::ModuleFFIntro()
{

	//Intro Background

	introwin.PushBack({ 0,0,316,194 });
	//borders.PushBack({ 0,446,304,225 });

	//Start Animation

	start.PushBack({ 590, 260, 146, 21 });
	start.PushBack({ 0, 700, 236, 44 });
	start.speed = 0.06f;

	//player

	player.PushBack({ 340, 37, 62, 127 });
	player.PushBack({ 411, 38, 62, 127 });
	player.PushBack({ 484, 38, 62, 127 });
	player.PushBack({ 553, 38, 62, 127 });
	player.PushBack({ 484, 38, 62, 127 });
	player.PushBack({ 411, 38, 62, 127 });
	player.PushBack({ 484, 38, 62, 127 });
	player.speed = 0.15f;

	//rock
	rock.PushBack({ 650,128,119,35 });

	//title FATAL FURY
	title.PushBack({ 338, 483, 436, 62 });

	//black border
	//border.PushBack({ 854, 10, 166, 276 });


}

ModuleFFIntro::~ModuleFFIntro()
{}

// Load assets
bool ModuleFFIntro::Start()
{
	LOG("Loading image assets");
	bool ret = true;

	fplayer = { 27,73 };
	frock = { -25,177 };
	animationState = Enter;
	step = 0;

	graphics = App->textures->Load("Resource/UI/Intro/intro2.png");
	introsong = App->audio->LoadMusic("Resource/Sound/Music/Opening.ogg");

	App->audio->PlayMusic(introsong);
	App->render->camera.x = -33;
	App->render->camera.y = 0;

	pos_player = 10;
	pos_rock = -20;
	pos_title = 300;
	//pos_border = 280;
	

	return ret;

}

bool ModuleFFIntro::CleanUp()
{
	LOG("Unloading FFINTRO");

	App->textures->Unload(graphics);

	//SDL_DestroyTexture(graphics);
	return true;
}

void ModuleFFIntro::RenderWords() {
	
	App->render->Blit(graphics, pos_rock, rock1.position.y, &(rock1.rect));
	App->render->Blit(graphics, pos_title, title1.position.y, &(title1.rect));
	App->render->Blit(graphics, pos_player, player1.position.y, &(player1.rect));
	App->render->DrawQuad({ 0,0,SCREEN_WIDTH,SCREEN_HEIGHT }, 255, 255, 255, 255, true);

}

// Update: draw background
update_status ModuleFFIntro::Update()
{
		App->render->Blit(graphics, 2, 16, &(introwin.GetCurrentFrame()), NULL);

		//App->render->Blit(graphics, pos_background, 16, &(introwin.GetCurrentFrame()), 0.75f);
		App->render->Blit(graphics, 110, 140, &(start.GetCurrentFrame()), 0.75f);
		App->render->Blit(graphics, pos_rock, 176, &(rock.GetCurrentFrame()), 0.75f);
		App->render->Blit(graphics, pos_title, 35, &(title.GetCurrentFrame()), 0.75f);
		App->render->Blit(graphics, pos_player, 73, &(player.GetCurrentFrame()), 0.75f);
		//App->render->Blit(graphics, pos_border, 0, &(border.GetCurrentFrame()), 0.75f);

		if (pos_rock < 0)
		{
			pos_player += 0.1;
			pos_rock += 0.1;
			//pos_background -= 0.02;
		}

		pos_title -= 1;
		

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {

		App->fade->FadeToBlack(App->scene_intro, App->scene_controls, 1.5);
	}

	if (SDL_GameControllerGetButton(App->input->gamepad2, SDL_CONTROLLER_BUTTON_START) == 1)
	{
		App->fade->FadeToBlack(App->scene_intro, App->scene_controls, 1.5);
	}
	if (SDL_GameControllerGetButton(App->input->gamepad1, SDL_CONTROLLER_BUTTON_START) == 1)
	{
		App->fade->FadeToBlack(App->scene_intro, App->scene_controls, 1.5);
	}



	return UPDATE_CONTINUE;
}