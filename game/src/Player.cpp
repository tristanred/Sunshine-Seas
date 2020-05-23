#include "Player.h"

#include <Input/AKeyboard.h>
#include <math.h>

Player::Player(GameEngine* engine) : RenderableObject(engine) {}

Player::~Player() {}

void Player::Setup(GameModule* currentModule)
{
    auto tex = this->GetEngine()->CreateTexture("Player.png");
    this->SetTexture(tex);

    this->velocity = vec2(0);
}

void Player::Update(unsigned int deltaTime)
{
    GameObject::Update(deltaTime);

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

    FPosition pos = this->GetPosition();
    pos.X += this->velocity.x;
    pos.Y += this->velocity.y;
    this->SetPosition(pos);
}
