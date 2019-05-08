#include "Player.h"

#include <Input/AKeyboard.h>

Player::Player()
    : GameObject()
{

}

Player::~Player()
{

}

void Player::Setup(GameModule* currentModule)
{
    GameObject::Setup(currentModule);

    this->PlayerSprite = currentModule->CreateSprite();
    this->PlayerSprite->SetTexture("Player.png");

    this->velocity = vec2(0);
}

void Player::Update(unsigned int deltaTime)
{
    GameObject::Update(deltaTime);

    this->PlayerSprite->Update(deltaTime);

    vec2_mul_scalar(&this->velocity, 0.90);

    if(this->GetEngine()->Keyboard->IsKeyDown(Key::D))
    {
        if(this->velocity.x < MAX_VELOCITY)
        {
            this->velocity.x += 1;
        }
    }
    if(this->GetEngine()->Keyboard->IsKeyDown(Key::S))
    {
        if(this->velocity.y < MAX_VELOCITY)
        {
            this->velocity.y += 1;
        }
    }
    if(this->GetEngine()->Keyboard->IsKeyDown(Key::A))
    {
        if(this->velocity.x < MAX_VELOCITY)
        {
            this->velocity.x -= 1;
        }
    }
    if(this->GetEngine()->Keyboard->IsKeyDown(Key::W))
    {
        if(this->velocity.y < MAX_VELOCITY)
        {
            this->velocity.y -= 1;
        }
    }

    FPosition pos = this->PlayerSprite->GetPosition();
    pos.X += this->velocity.x;
    pos.Y += this->velocity.y;
    this->PlayerSprite->SetPosition(pos);
}

void Player::Draw()
{
    GameObject::Draw();
}