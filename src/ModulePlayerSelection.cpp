#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"
#include "SDL\include\SDL.h"
#include "ModuleMusic.h"


//Scenes that we are going to need
#include "ModulePlayerSelection.h"
#include "ModuleSceneBillyKane.h"
#include "ModuleFFIntro.h"


ModulePlayerSelection::ModulePlayerSelection()
{

	//Pao Pao Background
	background.x = 4;
	background.y = 4;
	background.w = 288;
	background.h = 224;
	
	//Player Selection Title
	title.x = 576;
	title.y = 130;
	title.w = 120;
	title.h = 17;

	//PlayerNumber pointer
	player.x = 580;
	player.y = 170;
	player.w = 50;
	player.h = 17;


	//Characters Locked
	charlocked.x = 243;
	charlocked.y = 232;
	charlocked.w = 225;
	charlocked.h = 133;

	
	//Hover Terry Bogard
	hoverterry.PushBack({ 573, 237, 71, 128 });
	hoverterry.PushBack({ 95, 374, 71, 128 });
	hoverterry.speed = 0.07f;

	//Hover Joe Higashi
	hoverjoe.PushBack({482 , 231, 76 , 134});
	hoverjoe.PushBack({ 4 , 368 , 76 , 134 });
	hoverjoe.speed = 0.07f;

	//Hover Andy Bogard
	hoverandy.PushBack({ 178 , 379, 50 , 123 });
	hoverandy.PushBack({ 178 , 242 , 50 , 123 });
	hoverandy.speed = 0.07f;

}

ModulePlayerSelection::~ModulePlayerSelection()
{}

// Loading assets
bool ModulePlayerSelection::Start()
{

	LOG("Loading assets");
	bool ret = true;

	//Loading Map Assets Texture
	graphics = App->textures->Load("Resource/UI/Player_Map_Selection/SpriteSheet_PlayerSelection.png"); 

	//Loading Music and FX
	song = App->audio->LoadMusic("Resource/Sound/Music/CharacterSelection.ogg");
	choosefx = App->audio->LoadFX("Resource/Sound/FX/FX/FX_ChooseSelection.wav");
	hoverfx = App->audio->LoadFX("Resource/Sound/FX/FX/FX_SelectHover.wav");
	App->audio->PlayMusic(song);

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

bool ModulePlayerSelection::CleanUp()
{
	SDL_DestroyTexture(graphics);
	LOG("Textures from PlayerSelection Destroyed");	

	return true;
}

update_status ModulePlayerSelection::Update()
{
	//Background Rendered
	App->render->Blit(graphics, 15, 0, &background, NULL);
	App->render->Blit(graphics, 95, 40, &title, NULL);
	App->render->Blit(graphics, 35, 71, &charlocked, NULL);
	
	if (App->input->keyboard[SDL_SCANCODE_D] == 1 && selection < 2 || App->input->right == 1 && selection < 2 || App->input->right2 == 1 && selection < 2) {
		selection++;
		/*App->audio->PlayFX(hoverfx);*/
	}

	if (App->input->keyboard[SDL_SCANCODE_A] == 1 && selection > 0 || App->input->left == 1 && selection > 0  || App->input->left2 == 1 && selection  > 0) {
		selection--; 
		/*App->audio->PlayFX(hoverfx);*/
	}
	
	//CONDITION	TERRY'S HOVER WILL BE 1D[DEFAULT HOVER] IF selection--(A) will be JOE's HOVER, if D is pressed twice, selection += 2 will be ANDY's
	if (selection == 1) {
		App->render->Blit(graphics, 126, 76, &(hoverterry.GetCurrentFrame()), NULL);
		App->render->Blit(graphics, 134, 58, &player, NULL);
	}
	else {
		if (selection == 0) {
			App->render->Blit(graphics, 35, 70, &(hoverjoe.GetCurrentFrame()), NULL);
			App->render->Blit(graphics, 60, 55, &player, NULL);
		}
		else {
			App->render->Blit(graphics, 209,81, &(hoverandy.GetCurrentFrame()), NULL);
			App->render->Blit(graphics, 197, 55, &player, NULL);
		}
	}

	//If enter
	if (App->input->keyboard[SDL_SCANCODE_RETURN] == 1)
	{
		App->fade->FadeToBlack(App->playerselection, App->scene_billykane, 1.0);
		App->audio->PlayFX(choosefx);
	}

	if (SDL_GameControllerGetButton(App->input->gamepad2, SDL_CONTROLLER_BUTTON_START) == 1)
	{
		App->fade->FadeToBlack(App->playerselection, App->scene_billykane, 1.5);
		App->audio->PlayFX(choosefx);
	}
	if (SDL_GameControllerGetButton(App->input->gamepad1, SDL_CONTROLLER_BUTTON_START) == 1)
	{
		App->fade->FadeToBlack(App->playerselection, App->scene_billykane, 1.5);
		App->audio->PlayFX(choosefx);
	}


	return UPDATE_CONTINUE;
}