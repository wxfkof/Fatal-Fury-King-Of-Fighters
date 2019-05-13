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
#include "ModuleScenePaoPao.h"
#include "ModuleSceneBillyKane.h"



ModulePlayer2::ModulePlayer2()
{
	current_animation = NULL;
	graphics = NULL;

	//IDLE
	{

		//Terry Bogard Idle Animation
		idle.PushBack({ 870, 121, 60, 102 });
		/*idle.PushBack({ 877, 601, 64, 100 });
		idle.PushBack({ 870, 121, 60, 102 });
		idle.PushBack({ 877, 601, 64, 100 });*/

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


		/*//Andy Bogard Jump FORWARD Animation

		jumpf.PushBack({ 716, 927, 60, 96 });
		jumpf.PushBack({ 716, 927, 60, 96 });
		jumpf.PushBack({ 716, 927, 60, 96 });
		jumpf.PushBack({ 716, 927, 60, 96 });
		jumpf.PushBack({ 782, 918, 59, 106 });
		jumpf.PushBack({ 841, 941, 89, 55 });
		jumpf.PushBack({ 841, 941, 89, 55 });
		jumpf.PushBack({ 841, 941, 89, 55 });

		jumpf.speed = 0.12f;

		//Terry Bogard Jump BACKWARD Animation

		jumpb.PushBack({ 716, 927, 60, 96 });
		jumpb.PushBack({ 716, 927, 60, 96 });
		jumpb.PushBack({ 716, 927, 60, 96 });
		jumpb.PushBack({ 716, 927, 60, 96 });
		jumpb.PushBack({ 782, 918, 59, 106 });
		jumpb.PushBack({ 841, 941, 89, 55 });
		jumpb.PushBack({ 841, 941, 89, 55 });
		jumpb.PushBack({ 841, 941, 89, 55 });

		jumpb.speed = 0.12f;
		}*/

		//KICK
		{
			//Terry Bogard Kick Animation
			kick.PushBack({ 449, 806, 59, 107 });
			kick.PushBack({ 512, 803, 53, 107 });
			kick.PushBack({ 31, 1150, 50, 97 });
			kick.PushBack({ 84, 1148, 59, 115 });
			kick.PushBack({ 149, 1151, 50, 108 });
			kick.PushBack({ 211, 1155, 119, 108 });
			kick.PushBack({ 342, 1152, 68, 111 });
			kick.PushBack({ 714, 925, 64, 98 });
			kick.speed = 0.18f;

			/*//Terry Bogard Kick JUMPF Animation
			kickf.PushBack({ 577, 482, 59, 74 });
			kickf.PushBack({ 577, 482, 59, 74 });
			kickf.PushBack({ 577, 482, 59, 74 });
			kickf.PushBack({ 577, 482, 59, 74 });
			kickf.PushBack({ 640, 464, 80, 114 });
			kickf.PushBack({ 737, 485, 115, 72 });
			kickf.PushBack({ 737, 485, 115, 72 });
			kickf.PushBack({ 737, 485, 115, 72 });
			kickf.speed = 0.18f;

			//Terry Bogard Kick JUMPB Animation
			kickb.PushBack({ 577, 482, 59, 74 });
			kickb.PushBack({ 577, 482, 59, 74 });
			kickb.PushBack({ 577, 482, 59, 74 });
			kickb.PushBack({ 577, 482, 59, 74 });
			kickb.PushBack({ 640, 464, 80, 114 });
			kickb.PushBack({ 737, 485, 115, 72 });
			kickb.PushBack({ 737, 485, 115, 72 });
			kickb.PushBack({ 737, 485, 115, 72 });
			kickb.speed = 0.18f;

			//Terry Bogard Kick JUMPN Animation
			kickn.PushBack({ 376, 489, 58, 75 });
			kickn.PushBack({ 376, 489, 58, 75 });
			kickn.PushBack({ 376, 489, 58, 75 });
			kickn.PushBack({ 376, 489, 58, 75 });
			kickn.PushBack({ 447, 477, 75, 97 });
			kickn.PushBack({ 447, 477, 75, 97 });
			kickn.PushBack({ 447, 477, 75, 97 });
			kickn.speed = 0.18f;

			//Terry Bogard Kick Crouch Animation
			/*kickc.PushBack({ 449, 806, 59, 107 });
			kickc.PushBack({ 512, 803, 53, 107 });
			kickc.PushBack({ 31, 1150, 50, 97 });
			kickc.PushBack({ 84, 1148, 59, 115 });
			kickc.PushBack({ 149, 1151, 50, 108 });
			kickc.PushBack({ 211, 1155, 119, 108 });
			kickc.PushBack({ 342, 1152, 68, 111 });
			kickc.PushBack({ 714, 925, 64, 98 });
			kickc.speed = 0.18f;*/
		}

		//PUNCH

		// punch animation 

		punch.PushBack({ 15, 121, 60, 101 });
		punch.PushBack({ 88, 131, 51, 92  });
		punch.PushBack({ 154, 127, 50, 97 });
		punch.PushBack({ 219, 126, 95, 97 });
		punch.speed = 0.18f;

		/*// punch jumpf animation
		punchf.PushBack({ 23, 799, 65, 111 });
		punchf.PushBack({ 23, 799, 65, 111 });
		punchf.PushBack({ 23, 799, 65, 111 });
		punchf.PushBack({ 23, 799, 65, 111 });
		punchf.PushBack({ 91, 807, 53, 104 });
		punchf.PushBack({ 147, 809, 85, 101 });
		punchf.PushBack({ 147, 809, 85, 101 });
		punchf.PushBack({ 147, 809, 85, 101 });
		punchf.speed = 0.1f;

		// punch jumpb animation
		punchb.PushBack({ 23, 799, 65, 111 });
		punchb.PushBack({ 23, 799, 65, 111 });
		punchb.PushBack({ 23, 799, 65, 111 });
		punchb.PushBack({ 23, 799, 65, 111 });
		punchb.PushBack({ 91, 807, 53, 104 });
		punchb.PushBack({ 147, 809, 85, 101 });
		punchb.PushBack({ 147, 809, 85, 101 });
		punchb.PushBack({ 147, 809, 85, 101 });
		punchb.speed = 0.1f;

		// punch jumpn animation
		punchn.PushBack({ 719, 695, 46, 46 });
		punchn.PushBack({ 719, 695, 46, 46 });
		punchn.PushBack({ 719, 695, 46, 46 });
		punchn.PushBack({ 719, 695, 46, 46 });
		punchn.PushBack({ 769, 679, 70, 97 });
		punchn.PushBack({ 769, 679, 70, 97 });
		punchn.PushBack({ 769, 679, 70, 97 });
		punchn.speed = 0.1f;

		// punch crouch animation
		punchc.PushBack({ 261, 952, 61, 67 });
		punchc.PushBack({ 320, 954, 83, 67 });
		punchc.speed = 0.1f;
		}*/

		//SPECIAL MOVEMENTS

		//Special Movement 1

			sm1.PushBack({ 23, 357, 66, 99 });
			sm1.PushBack({ 92, 361, 52, 94 });
			sm1.PushBack({ 153, 364, 51, 94 });
			sm1.PushBack({ 216, 363, 99, 92 });

			sm1.speed = 0.17f;

	/*		//DAMAGE
			{
			//Low damage

			lowd.PushBack({ 24, 475, 60, 100 });
			lowd.PushBack({ 88, 469, 68, 107 });
			lowd.speed = 0.15f;

			//High damage

			highd.PushBack({ 160, 479, 65, 98 });
			highd.PushBack({ 235, 478, 70, 88 });
			highd.PushBack({ 88, 469, 68, 107 });
			highd.speed = 0.15f;

			//Hihgh High damage

			hhd.PushBack({ 75, 5, 101, 91 });
			hhd.PushBack({ 185, 48, 112, 44 });
			hhd.PushBack({ 299, 44, 116, 44 });
			hhd.PushBack({ 423, 41, 97, 47 });
			hhd.PushBack({ 523, 22, 82, 70 });
			hhd.PushBack({ 614, 19, 58, 74 });
			hhd.PushBack({ 677, 11, 58, 82 });
			hhd.PushBack({ 88, 469, 68, 107 });

			hhd.speed = 0.15f;
			}*/




	}
}

ModulePlayer2::~ModulePlayer2(){
}

// Load assets
bool ModulePlayer2::Start()
{

	LOG("Loading player textures");
	bool ret = true;
	colcreated = true;
	Activesm1 = true;

	graphics = App->textures->Load("Source/Sprites/Character_Sprites/Andy_Bogard/andy.png");
	Kick = App->audio->LoadFX("Source/Sound/FX/Voice/Attacks/Attack5.wav");
	Punch = App->audio->LoadFX("Source/Sound/FX/Voice/Attacks/Attack4.wav");
	Specialattack = App->audio->LoadFX("Source/Sound/FX/Voice/SpecialAttacks/PoweWave.wav");

	position.x = 100;
	position.y = 220;
	initialPos = position.y;

	playercol = App->collision->AddCollider({ 50, -250, 45, -103 }, COLLIDER_PLAYER, this);
	playerpunch = App->collision->AddCollider({ 0, 0, 0, 0 }, COLLIDER_PLAYER_SHOT, 0);
	playerkick = App->collision->AddCollider({ 0, 0, 0, 0 }, COLLIDER_PLAYER_SHOT, 0);

	return ret;

}

bool ModulePlayer2::CleanUp()
{
	SDL_DestroyTexture(graphics);
	App->player2->Disable();
	LOG("Unloading Andy From Scene");

	return true;
}

// Update: draw background
update_status ModulePlayer2::Update()
{

	Animation* current_animation = &idle;

	player_states current_state = ST_UNKNOWN;
	player_states state = process_fsm(App->input->inputs);

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

			current_animation = &idle;

			forward.Reset();
			backward.Reset();
			crouch.Reset();
			kick.Reset();
			punch.Reset();
			sm1.Reset();
			jump.Reset();

			break;

		case ST_WALK_FORWARD:

			current_animation = &forward;
			position.x += speed;

			backward.Reset();
			crouch.Reset();
			jump.Reset();
			kick.Reset();
			punch.Reset();
			sm1.Reset();

			break;

		case ST_WALK_BACKWARD:

			current_animation = &backward;
			position.x -= speed;

			forward.Reset();
			crouch.Reset();
			crouch.Reset();
			kick.Reset();
			punch.Reset();
			sm1.Reset();

			break;

		case ST_JUMP_NEUTRAL:

			/*if (position.y <= 220)
			{
				animdone = false;
				current_animation = &jump;
				position.y -= jumpspeed;
				jumpspeed -= 0.2;
			}

			if ((position.y == 220 && jump_timer > 0) || current_animation->AnimFinished() == true)
			{
				position.y = 220;
				jumpspeed = 6;
				animdone == true;
			}*/
			if (Active == 0)
			{
				position.y -= jumpSpeed;
				current_animation = &jump;

				if (attack == true)
				{
					//App->audio->PlayFX("AudioJUMP");
					attack = false;
				}

				if (position.y < 220) {
					jumpSpeed -= 0.5;
					if (jumpSpeed < 0) jumpSpeed = -6;
				}
				if (position.y >= initialPos && jumpSpeed < 0) {
					Active = 1;
					position.y = initialPos;
					jumpSpeed = 6;
				}
				LOG("JUMPING ^^\n")
			}

			break;

		case ST_JUMP_FORWARD:

			if (Active == 0)
			{
				current_animation = &jump;
				position.y -= jumpSpeed;
				position.x += 3;

				if (attack == true)
				{
					//App->audio->PlayFX("AudioJUMP");
					attack = false;
				}

				if (position.y < 220) {
					jumpSpeed -= 0.5;
					if (jumpSpeed < 0) jumpSpeed = -6;
				}
				if (position.y >= initialPos && jumpSpeed < 0) {
					Active = 1;
					position.y = initialPos;
					jumpSpeed = 6;
				}
			}
			LOG("JUMPING FORWARD ^^>>\n");

			break;

		case ST_JUMP_BACKWARD:

			if (Active == 0)
			{
				current_animation = &jump;
				position.y -= jumpSpeed;
				position.x -= 3;

				if (attack == true)
				{
					//App->audio->PlayFX("AudioJUMP");
					attack = false;
				}

				if (position.y < 220) {
					jumpSpeed -= 0.5;
					if (jumpSpeed < 0) jumpSpeed = -6;
				}
				if (position.y >= initialPos && jumpSpeed < 0) {
					Active = 1;
					position.y = initialPos;
					jumpSpeed = 6;
				}
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
				//App->audio->PlayFX("Audio");
				attack = false;
			}
			if (Active == 0)
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

			break;

		case ST_PUNCH_NEUTRAL_JUMP:


			if (attack == true)
			{
				//App->audio->PlayFX(Audio);
				attack = false;
			}
			if (Active == 0)
			{
				current_animation = &punchn;
			}
			LOG("PUNCH NEUTRAL JUMP ++++\n");

			/*if (position.y <= 220)
			{
				animdone = false;
				current_animation = &punchn;
				position.y -= jumpspeed;
				jumpspeed -= 0.2;
			}
			if ((position.y == 220 && punchn_timer > 0) || current_animation->AnimFinished() == true)
			{
				position.y = 220;
				jumpspeed = 6;
				animdone == true;
			}*/

			break;

		case ST_PUNCH_FORWARD_JUMP:

			LOG("PUNCH JUMP FORWARD ^>>+\n");

			break;

		case ST_PUNCH_BACKWARD_JUMP:

			LOG("PUNCH JUMP BACKWARD ^<<+\n");

			break;

		case ST_KICK_CROUCH:

			position.x += 0.5*speed;
			if (attack == true)
			{
				//App->audio->PlayFX(Audio);

				attack = false;
			}
			if (Active == 0)
			{
				current_animation = &kickc;
			}

			LOG("KICK CROUCHING **--\n");

			break;

		case ST_KICK_STANDING:

			if (attack == true)
			{
				//App->audio->PlayFX(Audio);
				attack = false;
			}
			if (Active == 0)
			{
				current_animation = &kick;
			}

			LOG("KICK --\n")

				break;

		case ST_KICK_NEUTRAL_JUMP:

			if (attack == true)
			{
				//App->audio->PlayFX(ryokick);
				attack = false;
			}
			if (Active == 0)
			{
				current_animation = &kickn;
			}
			LOG("KICK JUMP NEUTRAL ^^--\n");

			break;

		case ST_KICK_FORWARD_JUMP:

			LOG("KICK JUMP FORWARD ^>>-\n");

			break;

		case ST_KICK_BACKWARD_JUMP:

			LOG("KICK JUMP BACKWARD ^<<-\n");

			break;

		case ST_SM1:

			current_animation = &sm1;
			if (Activesm1 == true)
			{
				if ((position.x + 25) >= (App->player2->position.x - 25))
				{
					App->particles->AddParticle(App->particles->terryspecial1, position.x + 30, position.y - 90, COLLIDER_PLAYER_SHOT, 0);
				}

			Activesm1 = false;


			}
			break;


		/*case ST_LDAMAGE:

			if (dealtdamage == true) {

				current_animation = &lowd;

			}

			break;

		case ST_HDAGAME:

			/*if ()
			{
			current_animation=&highd
			}

			break;*/

		}

	}

	current_state = state;

	SDL_Rect r = current_animation->GetCurrentFrame();

	playercol->SetPos(position.x, position.y);
	playerpunch->SetPos(position.x + 40, position.y - 90);
	playerkick->SetPos(position.x + 40, position.y - 60);
		
	if (App->enemy2->position.x > position.x)
	{
			App->render->Blit(graphics, position.x, position.y - r.h, &r);
	}

	if (App->enemy2->position.x < position.x)
	{
			App->render->MirrorBlit(graphics, position.x, position.y - r.h, &r, 1.0f, 0, NULL);
	}

	if (App->enemy2->position.x > position.x) {
			
		playerpunch->SetPos(position.x + 40, position.y - 90);
		playerkick->SetPos(position.x + 40, position.y - 60);

	}
	
	if (App->enemy2->position.x < position.x) {
			
		playerpunch->SetPos(position.x - 40, position.y - 90);
		playerkick->SetPos(position.x - 40, position.y - 60);

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
			case IN_LEFT_DOWN: state = ST_WALK_BACKWARD; break;
			case IN_JUMP: state = ST_JUMP_NEUTRAL; App->input->jump_timer = SDL_GetTicks();  break;
			case IN_CROUCH_DOWN: state = ST_CROUCH; break;
			case IN_T: state = ST_PUNCH_STANDING, App->input->punch_timer = SDL_GetTicks(); break;
			case IN_R: state = ST_KICK_STANDING, App->input->kick_timer = SDL_GetTicks(); break;
			case IN_F: state = ST_SM1, App->input->sp1_timer = SDL_GetTicks(); break;

			}
		}
		break;

		case ST_WALK_FORWARD:
		{

			switch (last_input)
			{

			case IN_RIGHT_UP: state = ST_IDLE; break;
			case IN_LEFT_AND_RIGHT: state = ST_IDLE; break;
			case IN_JUMP: state = ST_JUMP_FORWARD;  App->input->jump_timer = SDL_GetTicks();  break;
			case IN_CROUCH_DOWN: state = ST_CROUCH; break;
			case IN_T: state = ST_PUNCH_STANDING, App->input->punch_timer = SDL_GetTicks(); break;
			case IN_R: state = ST_KICK_STANDING, App->input->kick_timer = SDL_GetTicks(); break;
			case IN_F: state = ST_SM1, App->input->sp1_timer = SDL_GetTicks(); break;

			}

		}
		break;

		case ST_WALK_BACKWARD:
		{

			switch (last_input)
			{

			case IN_LEFT_UP: state = ST_IDLE; break;
			case IN_LEFT_AND_RIGHT: state = ST_IDLE; break;
			case IN_JUMP: state = ST_JUMP_BACKWARD;  App->input->jump_timer = SDL_GetTicks();  break;
			case IN_CROUCH_DOWN: state = ST_CROUCH; break;
			case IN_T: state = ST_PUNCH_STANDING, App->input->punch_timer = SDL_GetTicks(); break;
			case IN_R: state = ST_KICK_STANDING, App->input->kick_timer = SDL_GetTicks(); break;
			case IN_F: state = ST_SM1, App->input->sp1_timer = SDL_GetTicks(); break;
			}
		}
		break;

		case ST_JUMP_NEUTRAL:
		{

			switch (last_input)
			{
			case IN_JUMP_FINISH: state = ST_IDLE; Active = 0; attack = true; break;
				//case IN_T: state = ST_PUNCH_NEUTRAL_JUMP;  punch_timer = SDL_GetTicks(); Active = 0; attack = true; break;
				//case IN_R: state = ST_KICK_NEUTRAL_JUMP; kick_timer = SDL_GetTicks(); Active = 0; attack = true; break;

			}
		}
		break;

		case ST_JUMP_FORWARD:
		{

			switch (last_input)
			{
			case IN_JUMP_FINISH: state = ST_IDLE; Active = 0; attack = true; break;
				//case IN_T: state = ST_PUNCH_FORWARD_JUMP;  punch_timer = SDL_GetTicks(); break;


			}
		}
		break;

		case ST_JUMP_BACKWARD:
		{

			switch (last_input)
			{

			case IN_JUMP_FINISH: state = ST_IDLE; Active = 0; attack = true; break;
				//case IN_T: state = ST_PUNCH_BACKWARD_JUMP;  punch_timer = SDL_GetTicks(); break;

			}

		}
		break;

		case ST_PUNCH_NEUTRAL_JUMP:
		{
			switch (last_input)
			{

				//case IN_PUNCH_FINISH: state = ST_JUMP_NEUTRAL; animstart = 0; attack = true; break;
			case IN_JUMP_FINISH: state = ST_IDLE; break;

			}

		}
		break;

		case ST_PUNCH_FORWARD_JUMP:
		{
			switch (last_input)
			{

			case IN_PUNCH_FINISH: state = ST_JUMP_FORWARD; break;
			case IN_JUMP_FINISH: state = ST_IDLE; break;

			}

		}
		break;

		case ST_PUNCH_BACKWARD_JUMP:
		{
			switch (last_input)
			{

			case IN_PUNCH_FINISH: state = ST_JUMP_BACKWARD; break;
			case IN_JUMP_FINISH: state = ST_IDLE; break;


			}
		}
		break;

		case ST_PUNCH_STANDING:
		{
			switch (last_input)
			{

			case IN_PUNCH_FINISH: state = ST_IDLE; Active = 0; attack = true; break;

			}
		}
		break;

		case ST_CROUCH:
		{
			switch (last_input)
			{

			case IN_CROUCH_UP: state = ST_IDLE; break;
			case IN_JUMP_AND_CROUCH: state = ST_IDLE; break;
			case IN_T: state = ST_PUNCH_CROUCH; App->input->punchc_timer = SDL_GetTicks(); break;
			case IN_R: state = ST_KICK_CROUCH; App->input->kickc_timer = SDL_GetTicks(); break;

			}
		}
		break;

		case ST_PUNCH_CROUCH:
		{
			switch (last_input)
			{

			case IN_PUNCH_CROUCH_FINISH:

				if (IN_CROUCH_DOWN == true)
				{
					state = ST_CROUCH; Active = 0; attack = true;

				}
				else
				{
					state = ST_IDLE; Active = 0; attack = true;
				}

			}
		}

		break;

		case ST_KICK_STANDING:
		{
			switch (last_input)
			{

			case IN_KICK_FINISH: state = ST_IDLE; Active = 0; attack = true; break;

			}

		}
		break;

		case ST_KICK_NEUTRAL_JUMP:
		{
			switch (last_input)
			{

			case IN_KICK_FINISH: state = ST_JUMP_NEUTRAL; Active = 0; attack = true; break;
			case IN_JUMP_FINISH: state = ST_IDLE; break;

			}
		}

		case ST_KICK_CROUCH:
		{
			switch (last_input)
			{
			case IN_KICK_CROUCH_FINISH:

				if (IN_CROUCH_DOWN == true)
				{
					state = ST_CROUCH; Active = 0; attack = true;

				}

				else
				{
					state = ST_IDLE; Active = 0; attack = true;
				}

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

		/*case ST_LDAMAGE:
		{

			switch (last_input) {

			case IN_LDAMAGE_FINISH: state = ST_IDLE; break;
			}
		}

		case ST_HDAGAME:
		{

			switch (last_input) {

			case IN_HDAMAGE_FINISH: state = ST_IDLE; break;
			}
		}

		}*/
		}
	}
	return state;

}

void ModulePlayer2::OnCollision(Collider* c1, Collider* c2) {

	if ( playercol == c1 && c2->type == COLLIDER_ENEMY && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT && App->enemy2->position.y == position.y && position.x < App->enemy2->position.x)
	{
		App->enemy2->position.x += 3;

	}

	if ( playercol == c1 && c2->type == COLLIDER_ENEMY && App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && App->enemy2->position.y == position.y && position.x > App->enemy2->position.x)
	{
		App->enemy2->position.x -= 3;

	}

	if (playerpunch == c1 && c2->type == COLLIDER_ENEMY)
	{
		if (playerpunch->callback!=nullptr)
		{
			playerpunch->to_delete = true;
		}
		App->enemy2->position.x += 3; 
			App->enemy2->life -= 25;


	}

	if (playerkick == c1 && c2->type == COLLIDER_ENEMY )
	{
		if (playerkick->callback != nullptr)
		{
			playerkick->to_delete = true;
		}
		App->enemy2->life -= 25;
		App->enemy2->position.x += 3;


	}

	else if (playercol == c1 && c2->type == COLLIDER_WALL)
	{
		position.x += 15;
		dealtdamage = true;
	}

}

/*bool ModulePlayer2::external_input(p2Qeue<player_inputs>& inputs)
{
	static bool backward = false;
	static bool forward = false;
	static bool crouch = false;
	static bool jump = false;
	
	SDL_Event event;

	while (SDL_PollEvent(&event) != 0)
	{
		if (event.type == SDL_KEYUP && event.key.repeat == 0)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				return false;
				break;

			case SDLK_s:
				inputs.Push(IN_CROUCH_UP);
				playercol->to_delete = true;
				playercol = App->collision->AddCollider({ 50, -250, 45, -103 }, COLLIDER_PLAYER, this);
				crouch = false;
				break;

			case SDLK_w:
				jump = false;
				break;

			case SDLK_a:
				inputs.Push(IN_LEFT_UP);
				backward = false;
				LOG("atras");
				break;

			case SDLK_d:
				inputs.Push(IN_RIGHT_UP);
				forward = false;
				break;

			case SDLK_t:
				break;

			case SDLK_y:
				
				App->audio->PlayFX(Kick);

				break;

			case SDLK_f:
				break;
			}
		}
		if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
		{
			switch (event.key.keysym.sym)
			{

			case SDLK_w:
				
				if (animdone == true)
				{
					jump = true;
				}
				//App->audio->PlayFX(AUDIOSALTO);

			break;

			case SDLK_s:
				playercol->to_delete = true;
				
				playercol = App->collision->AddCollider({ 50, -70, 45, -70 }, COLLIDER_PLAYER, this);
				crouch = true;

			break;

			case SDLK_a:

				backward = true;

			break;

			case SDLK_d:

				forward = true;

			break;

			case SDLK_t:

				inputs.Push(IN_PUNCH);
				if (colcreated == true)
				{
					playerpunch = App->collision->AddCollider({ 10, 30, 55, 10 }, COLLIDER_PLAYER_SHOT, this);
					playerkick = App->collision->AddCollider({ 0, 0, 0, 0 }, COLLIDER_PLAYER_SHOT, 0);
					colcreated = false;
				}
			break;

			case SDLK_y:

				if (colcreated == true)
				{
					playerkick = App->collision->AddCollider({ 10, 30, 75, 10 }, COLLIDER_PLAYER_SHOT, this);
					playerpunch = App->collision->AddCollider({ 0, 0, 0, 0 }, COLLIDER_PLAYER_SHOT, 0);
					colcreated = false;
				}
				inputs.Push(IN_KICK);

			break;

			case SDLK_f:

				if (Activesm1 == true) {

					App->particles->AddParticle(App->particles->terryspecial1, position.x + 48, position.y-90, COLLIDER_PLAYER_SHOT, 0);
					Activesm1 = false;
					forplayer = true;
				}

				App->audio->PlayFX(Specialattack);

				inputs.Push(IN_SM1);

			break;
			}

		}

	}

	if (backward && forward)
		inputs.Push(IN_LEFT_AND_RIGHT);
	else
	{
		if (backward)
			inputs.Push(IN_LEFT_DOWN);
		if (forward)
			inputs.Push(IN_RIGHT_DOWN);
	}

	if (jump && forward)
		inputs.Push(IN_JUMP_AND_RIGHT);
	else
	{
		if (forward)
			inputs.Push(IN_RIGHT_DOWN);
		if (jump)
			inputs.Push(IN_JUMP);
	}

	if (jump && backward)
		inputs.Push(IN_JUMP_AND_LEFT);
	else
	{
		if (backward)
			inputs.Push(IN_LEFT_DOWN);
		if (jump)
			inputs.Push(IN_JUMP);
	}

	return true;

}

void ModulePlayer2::internal_input(p2Qeue<player_inputs>& inputs)
{

	if (jump_timer > 0)
	{

		if (SDL_GetTicks() - jump_timer > JUMP_TIME && position.y == 220)
		{
			inputs.Push(IN_JUMP_FINISH);
			jump_timer = 0;

			position.y = 220;
			jumpspeed = 6;
			animdone = true;
		}


	}
	if (jumpf_timer > 0)
	{
	if (SDL_GetTicks() - jumpf_timer > JUMPF_TIME && position.y == 220)
		{
			inputs.Push(IN_JUMPF_FINISH);
			jumpf_timer = 0;

			position.y = 220;
			jumpspeed = 6;
			animdone = true;
		}
	}
	if (punch_timer > 0)
		{
			if (SDL_GetTicks() - punch_timer > PUNCH_TIME)
			{
				colcreated = true;
				playerpunch->to_delete = true;
				inputs.Push(IN_PUNCH_FINISH);
				punch_timer = 0;

			}
		}
	if (punchf_timer > 0)
		{
			if (SDL_GetTicks() - punchf_timer > PUNCHF_TIME)
			{
				//playerpunchf->to_delete = true;
				//colcreated = true;
				inputs.Push(IN_PUNCHF_FINISH);
				punchf_timer = 0;

			}
	}
	if (punchb_timer > 0)
	{
			if (SDL_GetTicks() - punchb_timer > PUNCHB_TIME)
			{
				//playerpunchb->to_delete = true;
				//colcreated = true;
				inputs.Push(IN_PUNCHB_FINISH);
				punchb_timer = 0;

			}
	}
	if (punchn_timer > 0)
	{
			if (SDL_GetTicks() - punchn_timer > PUNCHN_TIME)
			{
				//playerpunchn->to_delete = true;
				//colcreated = true;
				inputs.Push(IN_PUNCHN_FINISH);
				punchn_timer = 0;

			}
	}
	if (punchc_timer > 0)
	{
			if (SDL_GetTicks() - punchc_timer > PUNCHC_TIME)
			{
				//playerpunchc->to_delete = true;
				//colcreated = true;
				inputs.Push(IN_PUNCHC_FINISH);
				punchc_timer = 0;

			}
	}
	if (kick_timer > 0)
	{
			if (SDL_GetTicks() - kick_timer > KICK_TIME)
			{
				colcreated = true;
				playerkick->to_delete = true;
				inputs.Push(IN_KICK_FINISH);
				kick_timer = 0;
			}
	}
	if (kickf_timer > 0)
	{
			if (SDL_GetTicks() - kickf_timer > KICKF_TIME)
			{
				//colcreated = true;
				//playerkickf->to_delete = true;
				inputs.Push(IN_KICKF_FINISH);
				kickf_timer = 0;
			}
	}
	if (kickb_timer > 0)
	{
	if (SDL_GetTicks() - kickb_timer > KICKB_TIME)
	{
				//colcreated = true;
				//playerkickb->to_delete = true;
				inputs.Push(IN_KICKB_FINISH);
				kickb_timer = 0;
			}
	}
	if (kickn_timer > 0)
	{
			if (SDL_GetTicks() - kickn_timer > KICKN_TIME)
			{
				//colcreated = true;
				//playerkickn->to_delete = true;
				inputs.Push(IN_KICKN_FINISH);
				kickn_timer = 0;
			}
		}
	if (kickc_timer > 0)
		{
			if (SDL_GetTicks() - kickc_timer > KICKC_TIME)
			{
				//colcreated = true;
				//playerkickc->to_delete = true;
				inputs.Push(IN_KICKC_FINISH);
				kickc_timer = 0;
			}
		}
	if (sp1_timer > 0)
		{
			if (SDL_GetTicks() - sp1_timer > SP1_TIME)
			{
				inputs.Push(IN_SP1_FINISH);
				sp1_timer = 0;


			}
			if (SDL_GetTicks() - sp1_timer > SP1_TIME + 1500)
			{
				Activesm1 = true;

			}
			if (SDL_GetTicks() - sp1_timer > SP1_TIME + 2000)
			{
				App->particles->cont = 0;
				forplayer = false;

			}
		}
	if (ldamage_timer > 0)
		{
			if (SDL_GetTicks() - ldamage_timer > LDAMAGE_TIME)
			{
				inputs.Push(IN_LDAMAGE_FINISH);
				ldamage_timer = 0;

			}

		}
	if (hdamage_timer > 0)
	{
			if (SDL_GetTicks() - hdamage_timer > HDAMAGE_TIME)
			{
				inputs.Push(IN_HDAMAGE_FINISH);
				hdamage_timer = 0;

			}

		}
	if (hhdamage_timer > 0)
		{
			if (SDL_GetTicks() - hhdamage_timer > HHDAMAGE_TIME)
			{
				inputs.Push(IN_HHDAMAGE_FINISH);
				hhdamage_timer = 0;

			}

		}

}*/

