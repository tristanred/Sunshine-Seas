#include "Player.h"

#include <Input/AKeyboard.h>
#include <math.h>

Player::Player(GameEngine* engine)
    : GameObject(engine)
{
    this->PlayerSprite = NULL;
}

Player::~Player()
{

}

void Player::Setup(GameModule* currentModule)
{
    this->PlayerSprite = currentModule->CreateSprite();
    this->PlayerSprite->SetTexture("Player.png");

    this->velocity = vec2(0);
}

void Player::Update(unsigned int deltaTime)
{
    GameObject::Update(deltaTime);

    this->PlayerSprite->Update(deltaTime);

    vec2_mul_scalar(&this->velocity, 0.90f);

    if(this->GetEngine()->Keyboard->IsKeyDown(Key::D))
    {
        if(abs(this->velocity.x) < MAX_VELOCITY)
        {
            this->velocity.x += 1 * (deltaTime / 10);
        }
    }
    if(this->GetEngine()->Keyboard->IsKeyDown(Key::S))
    {
        if(abs(this->velocity.y) < MAX_VELOCITY)
        {
            this->velocity.y += 1 * (deltaTime / 10);
        }
    }
    if(this->GetEngine()->Keyboard->IsKeyDown(Key::A))
    {
        if(abs(this->velocity.x) < MAX_VELOCITY)
        {
            this->velocity.x -= 1 * (deltaTime / 10);
        }
    }
    if(this->GetEngine()->Keyboard->IsKeyDown(Key::W))
    {
        if(abs(this->velocity.y) < MAX_VELOCITY)
        {
            this->velocity.y -= 1 * (deltaTime / 10);
        }
    }

    FPosition pos = this->PlayerSprite->GetPosition();
    pos.X += this->velocity.x;
    pos.Y += this->velocity.y;
    this->PlayerSprite->SetPosition(pos);
}
