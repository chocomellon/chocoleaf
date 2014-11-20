#include "leaf.h"

leaf::leaf(AppEnv& app_env):
m_app_env(app_env),
set_point(Vec2f(0,0))
{
	angle = float(app_env.random().fromZeroToLast(50));
	Type = float(app_env.random().fromZeroToLast(4));
	switch (Type)
	{
	case TYPE::ONE:
		leaf_tex = new Texture("res/1.png");
		break;
	case TYPE::TWO:
		leaf_tex = new Texture("res/2.png");
		break;
	case TYPE::DUO:
		leaf_tex = new Texture("res/3.png");
		break;
	case TYPE::RED:
		leaf_tex = new Texture("res/4.png");
		break;
	}
	set_point = SetPoint(m_app_env); 
	m_pos = Vec2f(app_env.random().fromFirstToLast(-500, 500), app_env.random().fromFirstToLast(-300, 300));
}

leaf::~leaf()
{
}



void leaf::Draw(AppEnv& app_env){
		
	drawTextureBox(set_point.x(), set_point.y(), 100, 100,
		0, 0, 256, 256,
		*leaf_tex,
		Color(1, 1, 1),
		angle,
		Vec2f(1, 1),
		Vec2f(50, 50));

		drawCircle(set_point.x(), set_point.y(), 50, 50, 100, 1, Color(1, 1, 1));
}

void leaf::Update(){
	if (Check(m_app_env.mousePosition(), set_point, radius)){
		if (m_app_env.isPushButton(Mouse::LEFT)){
			set_point = SetPoint(m_app_env);
			
		}
		else if (m_app_env.isPushButton(Mouse::RIGHT)){
			set_point = Vec2f(500, 500);
		}

	}
	ang_s.x() =  -50;
	ang_s.y() =  50;
}

void leaf::Move(AppEnv& app_env){

	//set_point.x() += float(app_env.random().fromFirstToLast(-10,10))*2-1;
	//set_point.y() -= float(app_env.random().fromZeroToLast(5)) * 2 - 1;
	set_point.y() -= 7;
}

void leaf::LoadGraphics()
{

	
}