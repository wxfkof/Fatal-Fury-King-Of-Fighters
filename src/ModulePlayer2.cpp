#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleParticles.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer2.h"
#include "ModuleMusic.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModuleEnemy2.h"
#include "SDL\include\SDL.h"
#include "ModuleFonts.h"
#include "ModuleWelcomeScreen.h"
#include "ModuleSceneBillyKane.h"
#include "ModuleSceneBillyKane2.h"
#include "ModuleSceneBillyKane3.h"
#include "Animation.h"
#include "ModuleSlowdown.h"

ModulePlayer2::ModulePlayer2()
{
	current_animation = NULL;
	graphics = NULL;

	//IDLE
	{

		//Andy Bogard Idle Animation
		idle.PushBack({ 811, 341, 60, 101 });
		idle.PushBack({ 873, 343, 61, 100 });
		idle.PushBack({ 937, 346, 61, 98 });
		idle.PushBack({ 873, 343, 61, 100 });

		idle.speed = 0.18f;

	}

	//NORMAL MOVEMENTS (WALK AND CROUCH)
	{
		//Andy Bogard Forward Animation
		forward.PushBack({ 744, 602, 64, 99 });
		forward.PushBack({ 819, 601, 57, 100 });
		forward.PushBack({ 877, 601, 64, 100 });
		forward.PushBack({ 943, 599, 61, 102 });
		forward.speed = 0.15f;

		//Andy Bogard Backward Animation
		backward.PushBack({ 946, 476, 55, 97 });
		backward.PushBack({ 865, 474, 55, 99 });
		backward.PushBack({ 800, 471, 50, 102 });
		backward.PushBack({ 744, 473, 51, 100 });
		backward.speed = 0.15f;

		//crouch animation

		crouch.PushBack({ 946, 158, 51, 66 });
		crouch.speed = 0.2f;

	}

	//JUMP
	{

		//Andy Bogard Jump NEUTRAL Animation
		jump.PushBack({ 375, 121, 61, 102 });
		jump.PushBack({ 441, 142, 55, 81 });
		jump.PushBack({ 514, 118, 44, 106 });
		jump.PushBack({ 577, 117, 52, 95 });
		jump.PushBack({ 647, 121, 51, 85 });
		jump.PushBack({ 707, 142, 55, 81 });

		jump.speed = 0.12f;


		//Andy Bogard Jump FORWARD Animation

		jumpf.PushBack({ 728, 822, 58, 95 });
		jumpf.PushBack({ 802, 831, 69, 57 });
		jumpf.PushBack({ 884, 810, 50, 107 });

		jumpf.speed = 0.12f;

		//Terry Bogard Jump BACKWARD Animation

		jumpb.PushBack({ 728, 822, 58, 95 });
		jumpb.PushBack({ 802, 831, 69, 57 });
		jumpb.PushBack({ 884, 810, 50, 107 });

		jumpb.speed = 0.12f;

	}

	//KICK
	{
		//Terry Bogard Kick Animation
		kick.PushBack({ 310, 13, 47, 100 });
		kick.PushBack({ 378, 24, 57, 89 });
		kick.PushBack({ 448, 20, 54, 92 });
		kick.PushBack({ 506, 23, 126, 93 });
		kick.PushBack({ 641, 11, 85, 96 });
		kick.PushBack({ 747, 26, 55, 82 });
		kick.PushBack({ 832, 11, 61, 102 });

		kick.speed = 0.13f;

		//Terry Bogard Kick JUMPF Animation
		kickf.PushBack({ 305, 718, 52, 83 });
		kickf.PushBack({ 369, 721, 58, 77 });
		kickf.PushBack({ 435, 727, 96, 71 });

		kickf.speed = 0.1f;

		//Terry Bogard Kick JUMPB Animation
		kickb.PushBack({ 305, 718, 52, 83 });
		kickb.PushBack({ 369, 721, 58, 77 });
		kickb.PushBack({ 435, 727, 96, 71 });

		kickb.speed = 0.1f;

		//Terry Bogard Kick JUMPN Animation
		kickn.PushBack({ 713, 709, 57, 87 });
		kickn.PushBack({ 778, 710, 94, 89 });
		kickn.PushBack({ 778, 710, 94, 89 });
		kickn.PushBack({ 577, 117, 52, 95 });
		kickn.PushBack({ 647, 121, 51, 85 });
		kickn.PushBack({ 707, 142, 55, 81 });

		kickn.speed = 0.1f;

		//Terry Bogard Kick Crouch Animation
		kickc.PushBack({ 23, 739, 54, 62 });
		kickc.PushBack({ 93, 744, 68, 57 });
		kickc.PushBack({ 165, 765, 121, 36 });

		kickc.speed = 0.14f;
	}

	//PUNCH
	{
		// punch animation 

		punch.PushBack({ 15, 121, 60, 101 });
		punch.PushBack({ 88, 131, 51, 92 });
		punch.PushBack({ 154, 127, 50, 97 });
		punch.PushBack({ 219, 126, 95, 97 });

		punch.speed = 0.14f;

		// punch jumpf animation
		punchf.PushBack({ 19, 824, 52, 100 });
		punchf.PushBack({ 79, 824, 68, 94 });
		punchf.PushBack({ 152, 803, 57, 121 });
		punchf.PushBack({ 237, 815, 64, 97 });
		punchf.PushBack({ 314, 811, 81, 99 });

		punchf.speed = 0.1f;

		// punch jumpb animation
		punchb.PushBack({ 19, 824, 52, 100 });
		punchb.PushBack({ 79, 824, 68, 94 });
		punchb.PushBack({ 152, 803, 57, 121 });
		punchb.PushBack({ 237, 815, 64, 97 });
		punchb.PushBack({ 314, 811, 81, 99 });

		punchb.speed = 0.1f;

		// punch jumpn animation
		punchn.PushBack({ 234, 809, 70, 106 });
		punchn.PushBack({ 311, 807, 86, 106 });
		punchn.PushBack({ 311, 807, 86, 106 });
		punchn.PushBack({ 577, 117, 52, 95 });
		punchn.PushBack({ 647, 121, 51, 85 });
		punchn.PushBack({ 707, 142, 55, 81 });
		punchn.speed = 0.1f;

		// punch crouch animation
		punchc.PushBack({ 880, 734, 51, 65 });
		punchc.PushBack({ 942, 735, 79, 64 });

		punchc.speed = 0.1f;

	}

	//SPECIAL MOVEMENTS
	{
	//Special Movement 1

	sm1.PushBack({ 23, 357, 66, 99 });
	sm1.PushBack({ 92, 361, 52, 94 });
	sm1.PushBack({ 153, 364, 51, 94 });
	sm1.PushBack({ 153, 364, 51, 94 });
	sm1.PushBack({ 153, 364, 51, 94 });
	sm1.PushBack({ 216, 363, 99, 92 });
	sm1.PushBack({ 216, 363, 99, 92 });
	sm1.PushBack({ 216, 363, 99, 92 });


	sm1.speed = 0.15f;

	//special move 2

	sm2.PushBack({ 214, 473, 60, 97 });
	sm2.PushBack({ 276, 472, 61, 96 }); //concentracion
	sm2.PushBack({ 276, 472, 61, 96 }); //concentracion
	sm2.PushBack({ 338, 480, 78, 90 }); //dash1
	sm2.PushBack({ 424, 482, 92, 90 }); //dash2
	sm2.PushBack({ 424, 482, 92, 90 }); //dash2
	sm2.PushBack({ 424, 482, 92, 90 }); //dash2
	sm2.PushBack({ 424, 482, 92, 90 }); //dash2
	sm2.PushBack({ 516, 486, 88, 85 });
	sm2.PushBack({ 606, 472, 55, 97 });

	sm2.speed = 0.17f;

	//special move 3

	sm3.PushBack({ 18, 590, 63, 18 });
	sm3.PushBack({ 76, 616, 90, 92 }); 
	sm3.PushBack({ 165, 566, 94, 142 });
	sm3.PushBack({ 259, 580, 112, 128 }); 
	sm3.PushBack({ 382, 571, 88,146 }); 
	sm3.PushBack({ 488, 602, 64,106 }); 
	sm3.PushBack({ 563, 627, 55,81 }); 
	
	sm3.speed = 0.17f;

	// special move 4

	sm4.PushBack({ 104, 254, 90, 74 }); //start voltereta
	sm4.PushBack({ 111, 275, 83, 54 }); //voltereta
	sm4.PushBack({ 202, 228, 60, 100 }); //pino
	sm4.PushBack({ 271, 257, 89, 72 }); //patada 1
	sm4.PushBack({ 370, 258, 122, 71 }); //patada 2
	sm4.PushBack({ 511, 250, 127, 52 }); //patada 3
	sm4.PushBack({ 511, 250, 127, 52 }); //patada 3
	sm4.PushBack({ 511, 250, 127, 52 }); //patada 3
	sm4.PushBack({ 766, 249, 115, 59 }); //patada 4
	sm4.PushBack({ 784, 228, 62, 93 }); //patada finish / caida

	sm4.speed = 0.12f;

	}
	//DAMAGE
	{
		//Low damage

		lowd.PushBack({ 719, 918, 65, 97 });
		lowd.PushBack({ 784, 931, 67, 82 });
		lowd.speed = 0.15f;

		//High damage

		highd.PushBack({ 719, 918, 65, 97 });
		highd.PushBack({ 780, 931, 67, 84 });
		highd.PushBack({ 852, 920, 55, 95 });
		highd.PushBack({ 907, 931, 68, 81 });
		highd.speed = 0.15f;

		//Hihgh High damage


		hhd.PushBack({ 719, 918, 65, 97 });
		hhd.PushBack({ 780, 931, 67, 84 });
		hhd.PushBack({ 852, 920, 55, 95 });
		hhd.PushBack({ 907, 931, 68, 81 });
		hhd.PushBack({ 26, 934, 92, 81 });
		hhd.PushBack({ 125, 941, 100, 61 });
		hhd.PushBack({ 231, 942, 89, 56 });
		hhd.PushBack({ 315, 948, 101, 44 });
		hhd.PushBack({ 420, 953, 114, 38 });
		hhd.PushBack({ 521, 916, 109, 33 });


		hhd.speed = 0.15f;
	}

	//Shadow
	shadow.x = 644;
	shadow.y = 696;
	shadow.w = 65;
	shadow.h = 14;


}

ModulePlayer2::~ModulePlayer2() {
}

// Load assets
bool ModulePlayer2::Start()
{
	LOG("Loading player textures");
	App->particles->cont = 0;
	bool ret = true;
	colcreated = true;
	Activesm1 = true;

	graphics = App->textures->Load("Resource/Sprites/Character_Sprites/Andy_Bogard/andy.png");
	Kick = App->audio->LoadFX("Resource/Sound/FX/Voice/Attacks/Kick.wav");
	Punch = App->audio->LoadFX("Resource/Sound/FX/Voice/Attacks/Punch.wav");

	position.x = 200;
	position.y = 220;
	initialPos = position.y;

	playercol = App->collision->AddCollider({ 50, -250, 45, -103 }, COLLIDER_PLAYER, this);
	playerpunch = App->collision->AddCollider({ 0, 0, 0, 0 }, COLLIDER_PLAYER_SHOT, 0);
	playerkick = App->collision->AddCollider({ 0, 0, 0, 0 }, COLLIDER_PLAYER_SHOT, 0);
	playercrouchkick = App->collision->AddCollider({ 0, 0, 0, 0 }, COLLIDER_PLAYER_SHOT, 0);
	playercrouchpunch = App->collision->AddCollider({ 0, 0, 0, 0 }, COLLIDER_PLAYER_SHOT, 0);
	playerjumpnkick = App->collision->AddCollider({ 0, 0, 0, 0 }, COLLIDER_PLAYER_SHOT, 0);
	playerjumpnpunch = App->collision->AddCollider({ 0, 0, 0, 0 }, COLLIDER_PLAYER_SHOT, 0);
	playerdash = App->collision->AddCollider({ 0, 0, 0, 0 }, COLLIDER_PLAYER_SHOT, 0);
	playerjumpfkick = App->collision->AddCollider({ 0, 0, 0, 0 }, COLLIDER_PLAYER_SHOT, 0);
	playerjumpbkick = App->collision->AddCollider({ 0, 0, 0, 0 }, COLLIDER_PLAYER_SHOT, 0);
	playerjumpfpunch = App->collision->AddCollider({ 0, 0, 0, 0 }, COLLIDER_PLAYER_SHOT, 0);
	playerjumpbpunch = App->collision->AddCollider({ 0, 0, 0, 0 }, COLLIDER_PLAYER_SHOT, 0);
	playerwindmill = App->collision->AddCollider({ 0, 0, 0, 0 }, COLLIDER_PLAYER_SHOT, 0);
	//winanimation.Reset();

	return ret;

}

bool ModulePlayer2::CleanUp()
{
	//App->input->inputs.Push(IN_WIN_FINISH);

	SDL_DestroyTexture(graphics);
	App->player2->Disable();
	App->audio->Disable();
	// DANGER NEXT LINE IF USED CREATES EXCEPTION AND BREAKS GAME
	//App->audio->CleanUp();
	LOG("Unloading Andy From Scene");

	return true;
}

// Update: draw background
update_status ModulePlayer2::Update()
{
	
	Animation* current_animation = &idle;
	uint timersm1 = SDL_GetTicks();
	player_states current_state = ST_UNKNOWN;
	player_states state = process_fsm(App->input->inputs);

	App->render->Blit(graphics, position.x - 5, 210, &shadow, 1.0f, true);

	int speed = 2;

	//god mode
	if (App->input->keyboard[SDL_SCANCODE_F5] == KEY_STATE::KEY_DOWN) {

		if (godmode == false)
		{

			playercol->to_delete = true;


			godmode = true;
		}
		else if (godmode == true)
		{
			playercol = App->collision->AddCollider({ 50, -250, 45, -103 }, COLLIDER_PLAYER, this);

			godmode = false;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_STATE::KEY_DOWN) {

		App->enemy2->life = 0; //Kill Enemy

	}

	if (state != current_state)
	{

		switch (state)
		{

		case ST_IDLE:
			//////////
			current_animation = &idle;

			forward.Reset();
			backward.Reset();
			crouch.Reset();
			jump.Reset();
			jumpf.Reset();
			jumpb.Reset();


			kick.Reset();
			kickn.Reset();
			kickb.Reset();
			kickf.Reset();
			kickc.Reset();

			punch.Reset();
			punchn.Reset();
			punchb.Reset();
			punchf.Reset();
			punchc.Reset();
			sm1.Reset();
			sm2.Reset();
			sm3.Reset();
			sm4.Reset();

			hhd.Reset();
			highd.Reset();
			lowd.Reset();

			break;

		case ST_WALK_FORWARD:

			if (position.x > App->enemy2->position.x)
			{
				current_animation = &backward;
				forward.Reset();
			}
			else
			{
				current_animation = &forward;
				backward.Reset();
			}

			controllermover = true;
			position.x += speed;

			crouch.Reset();
			jump.Reset();
			jumpf.Reset();
			jumpb.Reset();

			kick.Reset();
			kickn.Reset();
			kickb.Reset();
			kickf.Reset();
			kickc.Reset();

			punch.Reset();
			punchn.Reset();
			punchb.Reset();
			punchf.Reset();
			punchc.Reset();
			sm1.Reset();
			sm2.Reset();
			sm3.Reset();
			sm4.Reset();

			hhd.Reset();
			highd.Reset();
			lowd.Reset();

			break;

		case ST_WALK_BACKWARD:

			if (position.x > App->enemy2->position.x)
			{
				current_animation = &forward;
				backward.Reset();
			}
			else
			{
				current_animation = &backward;
				forward.Reset();
			}

			controllermovel = true;
			position.x -= speed;

			crouch.Reset();
			jump.Reset();
			jumpf.Reset();
			jumpb.Reset();


			kick.Reset();
			kickn.Reset();
			kickb.Reset();
			kickf.Reset();
			kickc.Reset();

			punch.Reset();
			punchn.Reset();
			punchb.Reset();
			punchf.Reset();
			punchc.Reset();
			sm1.Reset();
			sm2.Reset();
			sm3.Reset();
			sm4.Reset();

			hhd.Reset();
			highd.Reset();
			lowd.Reset();

			break;

		case ST_JUMP_NEUTRAL:

			if (position.y <= 220)
			{
				animdone = false;
				current_animation = &jump;
				position.y -= jumpspeed;
				jumpspeed -= 0.2;
			}

			if (SDL_GetTicks() - App->input->jump_timer > JUMP_TIME && position.y == 220)
			{
				App->input->inputs.Push(IN_JUMP_FINISH);
				App->input->jump_timer = 0;

				position.y = 220;
				jumpspeed = 6;
				animdone = true;
			}

			break;

		case ST_JUMP_FORWARD:

			if (position.y <= 220)
			{
				animdone = false;
				current_animation = &jumpf;
				position.y -= jumpspeed;
				jumpspeed -= 0.2;
				position.x += 2;
			}

			if (SDL_GetTicks() - App->input->jump_timer > JUMP_TIME && position.y == 220)
			{
				App->input->inputs.Push(IN_JUMP_FINISH);
				App->input->jump_timer = 0;

				position.y = 220;
				jumpspeed = 6;
				animdone = true;
			}
			LOG("JUMPING FORWARD ^^>>\n");

			break;

		case ST_JUMP_BACKWARD:

			if (position.y <= 220)
			{
				animdone = false;
				current_animation = &jumpb;
				position.y -= jumpspeed;
				jumpspeed -= 0.2;
				position.x -= 2;
			}

			if (SDL_GetTicks() - App->input->jump_timer > JUMP_TIME && position.y == 220)
			{
				App->input->inputs.Push(IN_JUMP_FINISH);
				App->input->jump_timer = 0;

				position.y = 220;
				jumpspeed = 6;
				animdone = true;
			}
			LOG("JUMPING BACKWARD ^^<<\n");

			break;

		case ST_CROUCH:

			current_animation = &crouch;
			punchc.Reset();
			kickc.Reset();
			LOG("CROUCHING ****\n");

			break;

		case ST_PUNCH_CROUCH:

			if (attack == true)
			{
				attack = false;
				if (colcreated == true)
				{
					App->audio->PlayFX(Punch);
					playercrouchpunch = App->collision->AddCollider({ 10, 20, 35, 10 }, COLLIDER_PLAYER_SHOT, this);
					colcreated = false;
				}
			}
			if (SDL_GetTicks() - App->input->punchc_timer < PUNCHC_TIME)
			{
				current_animation = &punchc;
			}

			LOG("PUNCH CROUCHING **++\n");

			break;

		case ST_PUNCH_STANDING:
			if (attack == true)
			{
				App->audio->PlayFX(Punch);
				attack = false;
			}
			if (Active == 0)
			{
				current_animation = &punch;
			}
			LOG("PUNCH STANDING ++++\n");
			if (colcreated == true)
			{
				playerpunch = App->collision->AddCollider({ 10, 20, 55, 10 }, COLLIDER_PLAYER_SHOT, this);
				colcreated = false;
			}
			break;

		case ST_PUNCH_NEUTRAL_JUMP:


			if (position.y <= 220)
			{
				animdone = false;


				current_animation = &punchn;
				position.y -= jumpspeed;
				jumpspeed -= 0.2;
				if (colcreated == true)
				{
					App->audio->PlayFX(Punch);
					playerjumpnpunch = App->collision->AddCollider({ 10, 20, 55, 10 }, COLLIDER_PLAYER_SHOT, this);
					colcreated = false;
				}
			}


			if (SDL_GetTicks() - App->input->punchn_timer > PUNCHN_TIME && position.y == 220)
			{
				App->input->inputs.Push(IN_JUMP_FINISH);
				App->input->punchn_timer = 0;
				position.y = 220;
				jumpspeed = 6;
				animdone = true;
			}

			LOG("PUNCH NEUTRAL JUMP ++++\n");


			break;

		case ST_PUNCH_FORWARD_JUMP:

			if (position.y <= 220)
			{
				animdone = false;
				current_animation = &punchf;
				position.y -= jumpspeed;
				jumpspeed -= 0.2;
				position.x += 2;
				if (colcreated == true)
				{
					App->audio->PlayFX(Punch);
					playerjumpfpunch = App->collision->AddCollider({ 10, 20, 55, 10 }, COLLIDER_PLAYER_SHOT, this);
					colcreated = false;
				}
			}

			if (SDL_GetTicks() - App->input->punchf_timer > PUNCHF_TIME && position.y == 220)
			{
				App->input->inputs.Push(IN_JUMP_FINISH);
				App->input->punchf_timer = 0;
				playerjumpfpunch->to_delete = true;
				colcreated = true;
				position.y = 220;
				jumpspeed = 6;
				animdone = true;
			}

			LOG("PUNCH JUMP FORWARD ^>>+\n");

			break;

		case ST_PUNCH_BACKWARD_JUMP:

			if (position.y <= 220)
			{
				animdone = false;
				current_animation = &punchb;
				position.y -= jumpspeed;
				jumpspeed -= 0.2;
				position.x -= 2;
				if (colcreated == true)
				{
					App->audio->PlayFX(Punch);
					playerjumpbpunch = App->collision->AddCollider({ 10, 20, 55, 10 }, COLLIDER_PLAYER_SHOT, this);
					colcreated = false;
				}
			}

			if (SDL_GetTicks() - App->input->punchb_timer > PUNCHB_TIME && position.y == 220)
			{
				App->input->inputs.Push(IN_JUMP_FINISH);
				App->input->punchb_timer = 0;
				playerjumpbpunch->to_delete = true;
				colcreated = true;
				position.y = 220;
				jumpspeed = 6;
				animdone = true;
			}
			LOG("PUNCH JUMP BACKWARD ^<<+\n");

			break;

		case ST_KICK_CROUCH:

			if (attack == true)
			{
				
				if (colcreated == true)
				{
					App->audio->PlayFX(Kick);
					playercrouchkick = App->collision->AddCollider({ 10, 20, 100, 10 }, COLLIDER_PLAYER_SHOT, this);
				}
				attack = false;
			}
			if (SDL_GetTicks() - App->input->kickc_timer < KICKC_TIME)
			{
				current_animation = &kickc;
			}

			LOG("KICK CROUCHING **--\n");

			break;

		case ST_KICK_STANDING:

			if (position.y <= 220)
			{
				animdone = false;
				current_animation = &kick;

				//Check where should go fx	
				if (SDL_GetTicks() - App->input->kick_timer > 400 && position.y == 180)
				{
					position.y = 220;

				}

			}

			if (SDL_GetTicks() - App->input->kick_timer > KICK_TIME && position.y == 220)
			{
				App->input->inputs.Push(IN_KICK_FINISH);
				App->input->kick_timer = 0;

				position.y = 220;
				kick_jumpspeed = 6;
				animdone = true;
			}


			LOG("KICK --\n")
				if (App->player2->colcreated == true)
				{
					App->audio->PlayFX(Kick);
					App->player2->playerkick = App->collision->AddCollider({ 30, 100, 50, 10 }, COLLIDER_PLAYER_SHOT, this);
					App->player2->playerpunch = App->collision->AddCollider({ 0, 0, 0, 0 }, COLLIDER_PLAYER_SHOT, 0);
					App->player2->colcreated = false;
				}
			break;

		case ST_KICK_NEUTRAL_JUMP:


			if (position.y <= 220)
			{
				animdone = false;
				current_animation = &kickn;
				position.y -= jumpspeed;
				jumpspeed -= 0.2;
				if (colcreated == true)
				{
					App->audio->PlayFX(Kick);
					playerjumpnkick = App->collision->AddCollider({ 10, 20, 55, 10 }, COLLIDER_PLAYER_SHOT, this);
					colcreated = false;
				}

			}

			if (SDL_GetTicks() - App->input->kickn_timer > KICKN_TIME && position.y == 220)
			{
				App->input->inputs.Push(IN_JUMP_FINISH);
				App->input->kickn_timer = 0;
				position.y = 220;
				jumpspeed = 6;
				animdone = true;
			}

			LOG("KICK JUMP NEUTRAL ^^--\n");

			break;

		case ST_KICK_FORWARD_JUMP:

			if (position.y <= 220)
			{

				animdone = false;
				current_animation = &kickf;
				position.y -= jumpspeed;
				jumpspeed -= 0.2;
				position.x += 2;
				if (colcreated == true)
				{
					App->audio->PlayFX(Kick);
					playerjumpfkick = App->collision->AddCollider({ 10, 20, 55, 10 }, COLLIDER_PLAYER_SHOT, this);
					colcreated = false;
				}
			}

			if (SDL_GetTicks() - App->input->kickf_timer > KICKF_TIME && position.y == 220)
			{
				App->input->inputs.Push(IN_JUMP_FINISH);
				App->input->kickf_timer = 0;
				playerjumpfkick->to_delete = true;
				colcreated = true;
				position.y = 220;
				jumpspeed = 6;
				animdone = true;
			}

			LOG("KICK JUMP FORWARD ^>>-\n");

			break;

		case ST_KICK_BACKWARD_JUMP:

			if (position.y <= 220)
			{
				animdone = false;
				current_animation = &kickb;
				position.y -= jumpspeed;
				jumpspeed -= 0.2;
				position.x -= 2;
				if (colcreated == true)
				{
					App->audio->PlayFX(Kick);
					playerjumpbkick = App->collision->AddCollider({ 10, 20, 55, 10 }, COLLIDER_PLAYER_SHOT, this);
					colcreated = false;
				}
			}

			if (SDL_GetTicks() - App->input->kickb_timer > KICKB_TIME && position.y == 220)
			{
				App->input->inputs.Push(IN_JUMP_FINISH);
				App->input->kickb_timer = 0;
				playerjumpfkick->to_delete = true;
				colcreated = true;
				position.y = 220;
				jumpspeed = 6;
				animdone = true;
			}

			LOG("KICK JUMP BACKWARD ^<<-\n");

			break;

		case ST_SM1:
			
			current_animation = &sm1;
			if ((SDL_GetTicks() - App->input->sp1_timer) > 500)
			{
				App->particles->p1 = true;

				if (Activesm1 == true)
				{
					if (position.x < App->enemy2->position.x)
					{
						App->particles->AddParticle(App->particles->andyspecial1, position.x + 50, position.y - 90, COLLIDER_PLAYER_SHOT, 0);
					}
					else
					{
						App->particles->AddParticle(App->particles->andyspecial1, position.x - 30, position.y - 90, COLLIDER_PLAYER_SHOT, 0);
					}
					
					Activesm1 = false;
				}
			}
			
			break;

		case ST_SM2:

			current_animation = &sm2;
			if ((SDL_GetTicks() - App->input->sp2_timer) < SM2_TIME && (SDL_GetTicks() - App->input->sp2_timer) > 200)
			{
				if (colcreated == true)
				{
					App->audio->PlayFX(Punch);
					playerdash = App->collision->AddCollider({ 10, 20, 35, 10 }, COLLIDER_PLAYER_SHOT, this);
					colcreated = false;
				}
				if (position.x < App->enemy2->position.x)
				{
					position.x += dash_speed;
				}
				if (position.x > App->enemy2->position.x)
				{
					position.x -= dash_speed;
				}
				dash_speed -= 0.1;
			}
			

			break;

		case ST_SM3:

			

			current_animation = &sm3;
			

			if (attack == true)

			{
				//App->audio->PlayFX("Audio");
				attack = false;
			}
			if (Active == 0)
			{
				current_animation = &sm3;
			}
			LOG("SM3()()()()\n");
			if (colcreated == true)
			{
				playerwindmill = App->collision->AddCollider({ 10, 20, 55, 10 }, COLLIDER_PLAYER_SHOT, this);
				colcreated = false;
			}
		break;

		case ST_SM4:

			if (position.y <= 220 && (SDL_GetTicks() - App->input->sp4_timer) < SP4_TIME)
			{
				animdone = false;
				current_animation = &sm4;
				

				if ((SDL_GetTicks() - App->input->sp4_timer) > 300)
				{
					position.y -= flykick_speed;
					flykick_speed -= 0.14;
				}

				if (position.x < App->enemy2->position.x)
				{
					position.x += 2;
				}
				else
				{
					position.x -= 2;
				}
				
			}	

			LOG("SM4()()()()\n");
			
			
			break;
			
			
			

		case ST_LDAMAGE:

			if (App->enemy2->lowdamage1 == true)
			{
				current_animation = &lowd;
			}

			break;

		case ST_HDAMAGE:

			if (App->enemy2->highdamage1 == true)
			{
				current_animation = &highd;
			}

			break;

		case ST_HHDAMAGE:

			if (position.y <= 220 && App->enemy2->hhdamage1 == true)
			{
				animdone = false;
				current_animation = &hhd;
				position.y -= hhd_speed;
				hhd_speed -= 0.14;
				if (position.x < App->enemy2->position.x)
				{
					position.x -= 2;
				}
				else
				{
					position.x += 2;
				}
			}

			

			/*if (App->enemy2->hhdamage1 == true)
			{
				current_animation = &hhd;
			}*/

			break;


		}

	}

	current_state = state;

	SDL_Rect* r = &current_animation->GetCurrentFrame();

	playercol->SetPos(position.x, position.y);

	if (App->enemy2->position.x > position.x)
	{
		App->render->Blit(graphics, position.x + (current_animation->pivotx2[current_animation->returnCurrentFrame()]), position.y - r->h + current_animation->pivoty2[current_animation->returnCurrentFrame()], r);
	}

	if (App->enemy2->position.x < position.x)
	{
		App->render->BlitWithScale(graphics, position.x + 50 + (-current_animation->pivotx2[current_animation->returnCurrentFrame()]), position.y - r->h + current_animation->pivoty2[current_animation->returnCurrentFrame()], r, -1, 1.0f, 1, TOP_RIGHT);
	}

	if (App->enemy2->position.x > position.x) {

		playerpunch->SetPos(position.x + 40, position.y - 90);
		playerkick->SetPos(position.x + 60, position.y - 80);
		playercrouchpunch->SetPos(position.x + 40, position.y - 55);
		playercrouchkick->SetPos(position.x + 20, position.y - 20);
		playerjumpnkick->SetPos(position.x + 30, position.y - 15);
		playerjumpnpunch->SetPos(position.x + 35, position.y - 55);
		playerdash->SetPos(position.x + 35, position.y - 55);
		playerjumpfpunch->SetPos(position.x + 35, position.y - 55);
		playerjumpbpunch->SetPos(position.x + 35, position.y - 55);
		playerjumpfkick->SetPos(position.x + 35, position.y - 55);
		playerjumpbkick->SetPos(position.x + 35, position.y - 55);
		playerwindmill->SetPos(position.x + 57, position.y - 85);
	}

	if (App->enemy2->position.x < position.x) {

		playerpunch->SetPos(position.x - 40, position.y - 90);
		playerkick->SetPos(position.x - 60, position.y - 80);
		playercrouchpunch->SetPos(position.x - 40, position.y - 55);
		playercrouchkick->SetPos(position.x - 70, position.y - 20);
		playerjumpnkick->SetPos(position.x - 30, position.y - 15);
		playerjumpnpunch->SetPos(position.x - 30, position.y - 55);
		playerdash->SetPos(position.x - 35, position.y - 55);
		playerjumpfpunch->SetPos(position.x - 35, position.y - 55);
		playerjumpbpunch->SetPos(position.x - 35, position.y - 55);
		playerjumpfkick->SetPos(position.x - 35, position.y - 55);
		playerjumpbkick->SetPos(position.x - 35, position.y - 55);
		playerwindmill->SetPos(position.x - 57, position.y - 85);

	}

	playercol->SetPos(position.x, position.y);

	
	return UPDATE_CONTINUE;

}

player_states ModulePlayer2::process_fsm(p2Qeue<player_inputs>& inputs)
{

	static player_states state = ST_IDLE;
	player_inputs last_input;

	while (inputs.Pop(last_input))
	{
		switch (state)
		{

		case ST_IDLE:
		{
			switch (last_input)
			{

			case IN_RIGHT_DOWN: state = ST_WALK_FORWARD; break;
			case IN_LEFT_DOWN: state = ST_WALK_BACKWARD; timer_combo = SDL_GetTicks(); break;
			case IN_JUMP: state = ST_JUMP_NEUTRAL; App->input->jump_timer = SDL_GetTicks();  break;
			case IN_CROUCH_DOWN: state = ST_CROUCH; break;
			case IN_T: state = ST_PUNCH_STANDING, App->input->punch_timer = SDL_GetTicks(); break;
			case IN_R: 

				if (SDL_GetTicks() - combotime < 250) {
					if (combo1 == 2)combo1 = 3;
				}
				if (combo1 == 3)
				{
					state = ST_SM1; App->input->sp1_timer = SDL_GetTicks(); combo1 = 0; break;
				}
				if (SDL_GetTicks() - combotime < 250) {
					if (combo2 == 2)combo2 = 3;
				}
				if (combo2 == 3)
				{
					state = ST_SM2; App->input->sp2_timer = SDL_GetTicks(); combo2 = 0; break;
				}

				if (SDL_GetTicks() - combotime < 250) {
					if (combo3 == 2)combo3 = 3;
				}
				if (combo3 == 3)
				{
					state = ST_SM3; App->input->sp3_timer = SDL_GetTicks(); combo3 = 0; break;
				}

				else
				{
					state = ST_KICK_STANDING, App->input->kick_timer = SDL_GetTicks(); combo4 = 0; break;
				}

			case IN_F: state = ST_SM1, App->input->sp1_timer = SDL_GetTicks(); break;
			case IN_C: state = ST_SM2, App->input->sp2_timer = SDL_GetTicks(); break;
			case IN_X: state = ST_SM3, App->input->sp3_timer = SDL_GetTicks(); break;
			case IN_Z: state = ST_SM4, App->input->sp4_timer = SDL_GetTicks(); break;
			case IN_LDAMAGE: state = ST_LDAMAGE, App->input->ldamage_timer = SDL_GetTicks(); break;
			case IN_HDAMAGE: state = ST_HDAMAGE, App->input->hdamage_timer = SDL_GetTicks(); break;
			case IN_HHDAMAGE: state = ST_HHDAMAGE, App->input->hhdamage_timer = SDL_GetTicks(); break;
				//case IN_WIN: state = ST_WIN; Active = 0;  break;
			}
		}
		break;

		case ST_WALK_FORWARD:
		{
			//SM1 left side
			if ((position.x) <= (App->player2->position.x))
			{
				if (SDL_GetTicks() - combotime < 200)
				{
					if (combo1 == 1)combo1 = 2;
					combotime = SDL_GetTicks();
				}
				else
				{
					combo1 = 0;
				}
			}

			//SM3 left side
			if ((position.x) <= (App->player2->position.x))
			{
				if (SDL_GetTicks() - combotime < 200)
				{
					if (combo3 == 3)combo3 = 2;
					combotime = SDL_GetTicks();
				}
				else
				{
					combo3 = 0;
				}
			}



			switch (last_input)
			{

			case IN_RIGHT_UP: state = ST_IDLE; break;
			case IN_LEFT_AND_RIGHT: state = ST_IDLE; break;
			case IN_JUMP: state = ST_JUMP_FORWARD;  App->input->jump_timer = SDL_GetTicks();  break;
			case IN_CROUCH_DOWN: state = ST_CROUCH; break;
			case IN_T: state = ST_PUNCH_STANDING, App->input->punch_timer = SDL_GetTicks(); break;
			case IN_R: state = ST_KICK_STANDING, App->input->kick_timer = SDL_GetTicks(); break;
			case IN_F: state = ST_SM1, App->input->sp1_timer = SDL_GetTicks(); break;
			case IN_C: state = ST_SM2, App->input->sp2_timer = SDL_GetTicks(); break;
			case IN_X: state = ST_SM3, App->input->sp3_timer = SDL_GetTicks(); break;
			case IN_Z: state = ST_SM4, App->input->sp4_timer = SDL_GetTicks(); break;
			case IN_LDAMAGE: state = ST_LDAMAGE, App->input->ldamage_timer = SDL_GetTicks(); break;
			case IN_HDAMAGE: state = ST_HDAMAGE, App->input->hdamage_timer = SDL_GetTicks(); break;
			case IN_HHDAMAGE: state = ST_HHDAMAGE, App->input->hhdamage_timer = SDL_GetTicks(); break;
				//case IN_WIN: state = ST_WIN; Active = 0;  break;
			}

		}
		break;

		case ST_WALK_BACKWARD:
		{
			//SM2 LEFT SIDE
			if (SDL_GetTicks() - combotime < 200) {
				if (combo2 == 1)combo2 = 2;
				combotime = SDL_GetTicks();
			}
			else
			{
				combo2 = 0;
			}

			if (SDL_GetTicks() - combotime < 200) {
				if (combo3 == 1)combo3 = 2;
				combotime = SDL_GetTicks();
			}
			else
			{
				combo3 = 0;
			}
			

			
			switch (last_input)
			{

			case IN_LEFT_UP: state = ST_IDLE; break;
			case IN_LEFT_AND_RIGHT: state = ST_IDLE; break;
			case IN_JUMP: state = ST_JUMP_BACKWARD;  App->input->jump_timer = SDL_GetTicks();  break;
			case IN_CROUCH_DOWN: state = ST_CROUCH; break;
			case IN_T: state = ST_PUNCH_STANDING, App->input->punch_timer = SDL_GetTicks(); break;
			case IN_R: state = ST_KICK_STANDING, App->input->kick_timer = SDL_GetTicks(); break;
			case IN_F: state = ST_SM1, App->input->sp1_timer = SDL_GetTicks(); break;
			case IN_C: state = ST_SM2, App->input->sp2_timer = SDL_GetTicks(); break;
			case IN_X: state = ST_SM3, App->input->sp3_timer = SDL_GetTicks(); break;
			case IN_Z: state = ST_SM4, App->input->sp4_timer = SDL_GetTicks(); break;
				//case IN_WIN: state = ST_WIN; Active = 0;  break;

			}
		}
		break;

		case ST_JUMP_NEUTRAL:
		{

			switch (last_input)
			{
			case IN_JUMP_FINISH: state = ST_IDLE; Active = 0; attack = true; break;
			case IN_T: state = ST_PUNCH_NEUTRAL_JUMP; App->input->punchn_timer = SDL_GetTicks(); Active = 0; attack = true; break;
			case IN_R: state = ST_KICK_NEUTRAL_JUMP; App->input->kickn_timer = SDL_GetTicks(); Active = 0; attack = true; break;
				//case IN_WIN: state = ST_WIN; animstart = 0;  break;

			}
		}
		break;

		case ST_JUMP_FORWARD:
		{

			switch (last_input)
			{
			case IN_JUMP_FINISH: state = ST_IDLE; Active = 0; attack = true; break;
			case IN_T: state = ST_PUNCH_FORWARD_JUMP;  App->input->punchf_timer = SDL_GetTicks(); Active = 0; attack = true; break;
			case IN_R: state = ST_KICK_FORWARD_JUMP;  App->input->kickf_timer = SDL_GetTicks(); Active = 0; attack = true; break;
				//case IN_WIN: state = ST_WIN; Active = 0;  break;

			}
		}
		break;

		case ST_JUMP_BACKWARD:
		{

			switch (last_input)
			{

			case IN_JUMP_FINISH: state = ST_IDLE; Active = 0; attack = true; break;
			case IN_T: state = ST_PUNCH_BACKWARD_JUMP;  App->input->punchb_timer = SDL_GetTicks(); break;
			case IN_R: state = ST_KICK_BACKWARD_JUMP;  App->input->kickb_timer = SDL_GetTicks(); Active = 0; attack = true; break;
				//case IN_WIN: state = ST_WIN; Active = 0;  break;

			}

		}
		break;

		case ST_PUNCH_NEUTRAL_JUMP:
		{
			switch (last_input)
			{

			case IN_PUNCH_FINISH: state = ST_JUMP_NEUTRAL; break;
			case IN_JUMP_FINISH: state = ST_IDLE; break;
				//case IN_WIN: state = ST_WIN; Active = 0;  break;

			}

		}
		break;

		case ST_PUNCH_FORWARD_JUMP:
		{
			switch (last_input)
			{

			case IN_PUNCH_FINISH: state = ST_JUMP_FORWARD; break;
			case IN_JUMP_FINISH: state = ST_IDLE; break;
				//case IN_WIN: state = ST_WIN; Active = 0;  break;
			}

		}
		break;

		case ST_PUNCH_BACKWARD_JUMP:
		{
			switch (last_input)
			{

			case IN_PUNCH_FINISH: state = ST_JUMP_BACKWARD; break;
			case IN_JUMP_FINISH: state = ST_IDLE; break;
				//case IN_WIN: state = ST_WIN; Active = 0;  break;

			}
		}
		break;

		case ST_PUNCH_STANDING:
		{
			switch (last_input)
			{

			case IN_PUNCH_FINISH: state = ST_IDLE; Active = 0; attack = true; break;
			case IN_LDAMAGE: state = ST_LDAMAGE, App->input->ldamage_timer = SDL_GetTicks(); break;


			}
		}
		break;

		case ST_CROUCH:
		{
			playercol->to_delete = true;
			playercol = App->collision->AddCollider({ 50, -250, 45, -65 }, COLLIDER_PLAYER, this);
			
			combo1 = 1;
			combo2 = 1;
			combotime = SDL_GetTicks();

			if (SDL_GetTicks() - combosm1 < 120) {
				if (combo1 == 1)combo1 = 2;
				combosm1 = SDL_GetTicks();
			}
			if (SDL_GetTicks() - combosm2 < 120) {
				if (combo2 == 1)combo2 = 2;
				combosm2 = SDL_GetTicks();
			}


			switch (last_input)
			{

			case IN_CROUCH_UP: state = ST_IDLE; playercol->to_delete = true; playercol = App->collision->AddCollider({ 50, -250, 45, -103 }, COLLIDER_PLAYER, this); break;
			case IN_JUMP_AND_CROUCH: state = ST_IDLE; break;
			case IN_T: state = ST_PUNCH_CROUCH; App->input->punchc_timer = SDL_GetTicks(); break;
			case IN_R: state = ST_KICK_CROUCH; App->input->kickc_timer = SDL_GetTicks(); break;
			case IN_LDAMAGE: state = ST_LDAMAGE, App->input->ldamage_timer = SDL_GetTicks(); break;
			case IN_HDAMAGE: state = ST_HDAMAGE, App->input->hdamage_timer = SDL_GetTicks(); break;
				//case IN_WIN: state = ST_WIN; Active = 0;  break;

			}
		}
		break;

		case ST_PUNCH_CROUCH:
		{
			switch (last_input)
			{
			case IN_LDAMAGE: state = ST_LDAMAGE, App->input->ldamage_timer = SDL_GetTicks(); break;

			case IN_PUNCH_CROUCH_FINISH:

				if (IN_CROUCH_DOWN == true)
				{
					state = ST_CROUCH; Active = 0; attack = true;

				}
				else
				{
					state = ST_IDLE; Active = 0; attack = true;
					playercol->to_delete = true; playercol = App->collision->AddCollider({ 50, -250, 45, -103 }, COLLIDER_PLAYER, this);
				}

				//case IN_WIN: state = ST_WIN; Active = 0;  break;

			}
		}

		break;

		case ST_KICK_STANDING:
		{
			switch (last_input)
			{

			case IN_KICK_FINISH: state = ST_IDLE; playercol->to_delete = true; playercol = App->collision->AddCollider({ 50, -250, 45, -103 }, COLLIDER_PLAYER, this); attack = true; break;

			case IN_HDAMAGE: state = ST_HDAMAGE, App->input->hdamage_timer = SDL_GetTicks(); break;

				//case IN_WIN: state = ST_WIN; Active = 0;  break;

			}

		}
		break;

		case ST_KICK_NEUTRAL_JUMP:
		{
			switch (last_input)
			{

			case IN_KICK_FINISH: state = ST_JUMP_NEUTRAL; Active = 0; attack = true; break;
			case IN_JUMP_FINISH: state = ST_IDLE; break;
				//case IN_WIN: state = ST_WIN; Active = 0;  break;

			}
		}

		case ST_KICK_CROUCH:
		{
			switch (last_input)
			{

			case IN_HDAMAGE: state = ST_HDAMAGE, App->input->hdamage_timer = SDL_GetTicks(); break;

			case IN_KICK_CROUCH_FINISH:

				if (IN_CROUCH_DOWN == true)
				{
					state = ST_CROUCH; Active = 0; attack = true;

				}

				else
				{
					state = ST_IDLE; Active = 0; attack = true;
					playercol->to_delete = true; playercol = App->collision->AddCollider({ 50, -250, 45, -103 }, COLLIDER_PLAYER, this);
				}

				//case IN_WIN: state = ST_WIN; Active = 0;  break;

			}
		}

		case ST_SM1:
		{

			switch (last_input)
			{

			case IN_SM1_FINISH: state = ST_IDLE; Active = 0; Activesm1 = true; break;

			}
			break;

		}

		case ST_SM2:
		{

			switch (last_input)
			{

			case IN_SM2_FINISH: state = ST_IDLE; Active = 0; Activesm2 = true; break;

			}
			break;

		}

		case ST_SM3:
		{

			switch (last_input)
			{

			case IN_SM3_FINISH: state = ST_IDLE; Active = 0; Activesm3 = true; break;

			}
			break;

		}

		case ST_SM4:
		{

			switch (last_input)
			{

			case IN_SM4_FINISH: state = ST_IDLE; Active = 0; /*Activesm4 = true*/; break;

			}
			break;

		}

		case ST_KICK_FORWARD_JUMP:
		{
			switch (last_input)
			{

			case IN_KICK_FINISH: state = ST_JUMP_FORWARD; break;
			case IN_JUMP_FINISH: state = ST_IDLE; break;
				//case IN_WIN: state = ST_WIN; Active = 0;  break;

			}

		}
		break;

		case ST_KICK_BACKWARD_JUMP:
		{
			switch (last_input)
			{

			case IN_KICK_FINISH: state = ST_JUMP_BACKWARD; break;
			case IN_JUMP_FINISH: state = ST_IDLE; break;
				//case IN_WIN: state = ST_WIN; Active = 0;  break;

			}

		}
		break;

		case ST_LDAMAGE:
		{

			switch (last_input) {

			case IN_LDAMAGE_FINISH: state = ST_IDLE; Active = 0;  break;
			}
		}

		case ST_HDAMAGE:
		{

			switch (last_input) {

			case IN_HDAMAGE_FINISH: state = ST_IDLE; Active = 0; break;
			}
		}

		case ST_HHDAMAGE:
		{

			switch (last_input) {

			case IN_HHDAMAGE_FINISH: state = ST_IDLE; Active = 0; break;
			}
		}

		/*case ST_WIN:

		switch (last_input)
		{
		case IN_WIN_FINISH: state = ST_IDLE; Active = 0; break;

		}
		break;*/


		}
	}
	return state;

}

void ModulePlayer2::OnCollision(Collider* c1, Collider* c2) {

	if (playercol == c1 && c2->type == COLLIDER_ENEMY && App->enemy2->position.y == position.y && position.x < App->enemy2->position.x/* || playercol == c1 && c2->type == COLLIDER_ENEMY && controllermover == true*/)
	{
		App->enemy2->position.x += 3;

	}

	if (playercol == c1 && c2->type == COLLIDER_ENEMY && App->enemy2->position.y == position.y && position.x > App->enemy2->position.x/* || playercol == c1 && c2->type == COLLIDER_ENEMY && controllermovel == true*/)
	{
		App->enemy2->position.x -= 3;

	}

	if (playerpunch == c1 && c2->type == COLLIDER_ENEMY)
	{

		App->render->StartCameraShake(250, 3);
		App->render->UpdateCameraShake();
		playerpunch->to_delete = true;
		lowdamage2 = true;
		App->input->inputs2.Push(IN_LDAMAGE2);
		App->enemy2->position.x += 3;
		App->enemy2->life -= 10;
		//TRYING RUMBLE
		SDL_HapticRumblePlay(App->input->haptic, 0.2f, 500);
	}
	if (playercrouchpunch == c1 && c2->type == COLLIDER_ENEMY)
	{

		App->render->StartCameraShake(250, 3);
		App->render->UpdateCameraShake();
		playercrouchpunch->to_delete = true;
		lowdamage2 = true;
		App->input->inputs2.Push(IN_LDAMAGE2);
		App->enemy2->position.x += 3;
		App->enemy2->life -= 10;

		//TRYING RUMBLE
		SDL_HapticRumblePlay(App->input->haptic, 0.2f, 500);
	}
	if (playerjumpnpunch == c1 && c2->type == COLLIDER_ENEMY)
	{
		App->render->StartCameraShake(250, 3);
		App->render->UpdateCameraShake();
		playerjumpnpunch->to_delete = true;
		lowdamage2 = true;
		App->input->inputs2.Push(IN_LDAMAGE2);
		App->enemy2->position.x += 3;
		App->enemy2->life -= 10;

		//TRYING RUMBLE
		SDL_HapticRumblePlay(App->input->haptic, 0.2f, 500);
	}
	if (playerjumpfpunch == c1 && c2->type == COLLIDER_ENEMY)
	{
		playerjumpfpunch->to_delete = true;
		App->render->StartCameraShake(250, 3);
		App->render->UpdateCameraShake();
		lowdamage2 = true;
		App->input->inputs2.Push(IN_LDAMAGE2);
		App->enemy2->position.x += 3;
		App->enemy2->life -= 10;

		//TRYING RUMBLE
		SDL_HapticRumblePlay(App->input->haptic, 0.2f, 500);
	}
	if (playerjumpbpunch == c1 && c2->type == COLLIDER_ENEMY)
	{
		playerjumpbpunch->to_delete = true;
		App->render->StartCameraShake(250, 3);
		App->render->UpdateCameraShake();
		lowdamage2 = true;
		App->input->inputs2.Push(IN_LDAMAGE2);
		App->enemy2->position.x += 3;
		App->enemy2->life -= 10;

		//TRYING RUMBLE
		SDL_HapticRumblePlay(App->input->haptic, 0.2f, 500);
	}
	if (playerkick == c1 && c2->type == COLLIDER_ENEMY)
	{

		App->render->StartCameraShake(250, 3);
		App->render->UpdateCameraShake();
		playerkick->to_delete = true;
		highdamage2 = true;
		App->input->inputs2.Push(IN_HDAMAGE2);
		App->enemy2->life -= 10;
		App->enemy2->position.x += 3;

		//TRYING RUMBLE
		SDL_HapticRumblePlay(App->input->haptic, 0.2f, 500);
		LOG("MUST RUMBLE");
	}
	if (playerjumpnkick == c1 && c2->type == COLLIDER_ENEMY)
	{

		App->render->StartCameraShake(250, 3);
		App->render->UpdateCameraShake();
		playerjumpnkick->to_delete = true;
		highdamage2 = true;
		App->input->inputs2.Push(IN_HDAMAGE2);
		App->enemy2->life -= 10;
		App->enemy2->position.x += 3;

		//TRYING RUMBLE
		SDL_HapticRumblePlay(App->input->haptic, 0.2f, 500);
		LOG("MUST RUMBLE");
	}
	if (playerjumpbkick == c1 && c2->type == COLLIDER_ENEMY)
	{

		App->render->StartCameraShake(250, 3);
		App->render->UpdateCameraShake();
		playerjumpbkick->to_delete = true;
		highdamage2 = true;
		App->input->inputs2.Push(IN_HDAMAGE2);
		App->enemy2->life -= 10;
		App->enemy2->position.x += 3;

		//TRYING RUMBLE
		SDL_HapticRumblePlay(App->input->haptic, 0.2f, 500);
		LOG("MUST RUMBLE");
	}
	if (playerjumpfkick == c1 && c2->type == COLLIDER_ENEMY)
	{

		App->render->StartCameraShake(250, 3);
		App->render->UpdateCameraShake();
		playerjumpfkick->to_delete = true;
		highdamage2 = true;
		App->input->inputs2.Push(IN_HDAMAGE2);
		App->enemy2->life -= 10;
		App->enemy2->position.x += 3;

		//TRYING RUMBLE
		SDL_HapticRumblePlay(App->input->haptic, 0.2f, 500);
		LOG("MUST RUMBLE");
	}
	if (playercrouchkick == c1 && c2->type == COLLIDER_ENEMY)
	{

		App->render->StartCameraShake(250, 3);
		App->render->UpdateCameraShake();
		playercrouchkick->to_delete = true;
		highdamage2 = true;
		App->input->inputs2.Push(IN_HDAMAGE2);
		App->enemy2->life -= 10;
		App->enemy2->position.x += 3;

		//TRYING RUMBLE
		SDL_HapticRumblePlay(App->input->haptic, 0.2f, 500);




	}

	if (playerdash == c1 && c2->type == COLLIDER_ENEMY)
	{

		App->render->StartCameraShake(250, 3);
		App->render->UpdateCameraShake();
		playerdash->to_delete = true;
		highdamage2 = true;
		App->input->inputs2.Push(IN_HDAMAGE2);
		App->enemy2->life -= 20;
		App->enemy2->position.x += 3;
		//TRYING RUMBLE
		SDL_HapticRumblePlay(App->input->haptic, 0.2f, 500);


	}

	if (playerwindmill == c1 && c2->type == COLLIDER_ENEMY)
	{

		App->render->StartCameraShake(250, 3);
		App->render->UpdateCameraShake();
		playerwindmill->to_delete = true;
		highdamage2 = true;
		App->input->inputs2.Push(IN_HDAMAGE2);
		App->enemy2->life -= 20;
		App->enemy2->position.x += 3;
		//TRYING RUMBLE
		SDL_HapticRumblePlay(App->input->haptic, 0.2f, 500);


	}

	if (playercol == c1 && App->scene_billykane->wall2c == c2)   //Colisions with second wall
	{
		position.x -= 2;

	}
	if (playercol == c1 && App->scene_billykane2->wall2c == c2)   //Colisions with second wall
	{
		position.x -= 2;

	}
	if (playercol == c1 && App->scene_billykane3->wall2c == c2)   //Colisions with second wall
	{
		position.x -= 2;

	}
	if (playercol == c1 && App->scene_billykane->wall1c == c2)   //Colisions with first wall
	{
		position.x += 2;

	}
	if (playercol == c1 && App->scene_billykane2->wall1c == c2)   //Colisions with first wall
	{
		position.x += 2;

	}
	if (playercol == c1 && App->scene_billykane3->wall1c == c2)   //Colisions with first wall
	{
		position.x += 2;

	}
	if (App->enemy2->life <= 0)
	{
		/*App->slowdown->StartSlowdown(500, 40);
		App->slowdown->UpdateSlowdown();*/
	}
}