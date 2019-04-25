#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "SDL\include\SDL.h"
#include "ModuleMusic.h"
#include "ModuleCollision.h"
#include "ModuleEnemy.h"


#include "ModulePlayerSelection.h"
#include "ModuleScenePaoPao.h"
#include "ModuleSceneSoundBeach.h"
#include "ModuleWelcomeScreen.h"
#include "ModuleP1Wins.h"
#include "ModuleP2Wins.h"
#include "ModuleFFIntro.h"
#include "ModuleWelcomeScreen.h"
#include "ModuleFonts.h"


ModuleP1Wins::ModuleP1Wins()
{

	//WinP1 Background
	background.x = 0;
	background.y = 0;
	background.w = 290;
	background.h = 225;
}

ModuleP1Wins::~ModuleP1Wins()
{}

// Load assets
bool ModuleP1Wins::Start()
{
	music = App->audio->LoadMusic("Source/Sound/Music/winner.ogg");
	//fx = App->audio->LoadFX("Source/Sound/FX/FX/FX_audience.wav");
	//Mix_VolumeChunk(fx, 35);

	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("Source/UI/WinLose/Background.png");


	sentence_font = App->fonts->Load("Source/UI/fonts/PlayerWords.png", "ABCDEFGHIJKLMNOPQRSTUVWZYZ1234567890&?!()abcdefghijklmnopqrstuvwxyz.,'<>", 1);


	//Enabling audio
	App->audio->PlayMusic(music);
	//App->audio->PlayFX(fx); //Fix: Loop infinite(maybe convert to ogg and play as audio)

	return ret;
}

bool ModuleP1Wins::CleanUp()
{
	
	SDL_DestroyTexture(graphics);



	return true;
}

// Update: draw background
update_status ModuleP1Wins::Update()
{
	// Drawing background - WinP1 Background
	uint cont = SDL_GetTicks();
	App->render->Blit(graphics, 0, 0, &background, 0.75f);
	//App->fonts->BlitText(100, 50, sentence_font, "1");

	if (cont = SDL_GetTicks()+1100)
	{
		App->fade->FadeToBlack(App->p1w, App->p2w, 6);
	}
	return UPDATE_CONTINUE;
}