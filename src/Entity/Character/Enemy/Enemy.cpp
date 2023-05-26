#include "..\..\..\..\include\Entity\Character\Enemy\Enemy.h"

using namespace Whispers::Entity::Character;

Enemy::Enemy::Enemy(const Vector2f pos, const Vector2f size, Player *pP)
    : Character(pos, size, ENEMY_SPEED), player(pP), dtAux(0.0f)
{
    shape.setFillColor(Color::Red);
    init();
    srand(time(NULL));
    randomMove = rand() % 3;
    if (randomMove == 0)
    {
        stop();
    }
    else if (randomMove == 1)
    {
        walk(true);
    }
    else
    {
        walk(false);
    }
}

Enemy::Enemy::~Enemy() {}

void Enemy::Enemy::init() {}

// void Enemy::Enemy::chasePlayer(Vector2f pP, Vector2f eP) {
//     if (pP.x - eP.x > 0.0f) {
//         shape.move(speed.x, 0.0f);
//     } else {
//         shape.move(-speed.x, 0.0f);
//     }
//     if (pP.y - eP.y > 0.0f) {
//         shape.move(0.0f, speed.y);
//     } else {
//         shape.move(0.0f, -speed.y);
//     }
// }

void Enemy::Enemy::randomMovement()
{
    // dtAux = clock.getElapsedTime().asSeconds();
    if (dtAux >= 3.0f)
    {
        randomMove = rand() % 3;
        if (randomMove == 0)
        {
            stop();
        }
        else if (randomMove == 1)
        {
            walk(true);
        }
        else
        {
            walk(false);
        }
        dtAux = 0.0f;
    }
}

void Enemy::Enemy::update()
{
    Vector2f playerPos = player->getPosition();
    Vector2f enemyPos = getPosition();

    if (fabs(playerPos.x - enemyPos.x) <= CHASE_RAY_X &&
        fabs(playerPos.y - enemyPos.y) <= CHASE_RAY_Y)
    {
        if (playerPos.x - enemyPos.x > 0.0f)
        {
            walk(false);
        }
        else
        {
            walk(true);
        }
    }
    else
    {
        randomMovement();
    }
    updatePosition();
    dtAux += clock.getElapsedTime().asSeconds();
    clock.restart();
}
void Enemy::Enemy::Colission(bool ent)
{
    if (ent)
    {
        shape.setFillColor(Color::Magenta);
    }
    else
    {
        shape.setFillColor(Color::Cyan);
    }
}