#pragma once

#include "lib/appEnv.hpp"


class leaf
{
public:
	leaf(AppEnv& app_env);
	~leaf();

	enum TYPE{
		ONE,
		TWO,
		DUO,
		RED
	};

	Texture* leaf_tex;

	int Type;
	float angle;

	Vec2f ang_s;


	static int type;

	float radius = 50;

	AppEnv& m_app_env;
	
	Vec2f m_pos;

	Vec2f set_point;
	//	点と円の当たり判定
	bool Check(Vec2f pos, Vec2f obj_pos, float  radius)
	{
		if ((pos.x() - obj_pos.x())*(pos.x() - obj_pos.x()) + (pos.y() - obj_pos.y()) * (pos.y() - obj_pos.y()) <= radius*radius)
		{
			return true;
		}
		else return false;
	}

	//	乱数を用いて位置を決める
	Vec2f SetPoint(AppEnv& app_env){
		float x = app_env.random().fromFirstToLast(-500, 500);
		float y = app_env.random().fromFirstToLast(-300, 300);

		return Vec2f(x, y);
	}

	void Draw(AppEnv& app_env);
	void Update();
	void Move(AppEnv& app_env);
	void LoadGraphics();
};

