#pragma once
#include "Hero.hpp"

// Klon Itachi.
// Beda dengan NarutoClone (flog -> hero -> tower), klon ini
// memprioritaskan HERO dulu, lalu flog, lalu tower.
class ItachiClone : public Hero
{
	void perform() override
	{
		if (notFindHero(0))
		{
			if (notFindFlog(0))
			{
				if (notFindTower(0))
				{
					_mainTarget = nullptr;
				}
			}
		}

		if (_mainTarget)
		{
			Vec2 moveDirection;
			Vec2 sp = getDistanceToTarget();

			if (abs(sp.x) > 32 || abs(sp.y) > 32)
			{
				moveDirection = sp.getNormalized();
				walk(moveDirection);
			}
			else
			{
				if (isFreeState())
				{
					changeSide(sp);
					attack(NAttack);
				}
			}

			return;
		}

		stepOn();
	}
};
