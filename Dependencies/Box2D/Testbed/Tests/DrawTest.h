#ifndef DRAWTEST_H
#define DRAWTEST_H

#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f 

class DrawTest : public Test
{
public:
	b2Body* dbody;

	DrawTest() { 
	
		b2BodyDef bodyDef;
		bodyDef.type = b2_staticBody;
		bodyDef.position.Set(-8, 0);
		bodyDef.angle = 0;

		b2Body* lbox = m_world->CreateBody(&bodyDef);
		b2PolygonShape shape;
		shape.SetAsBox(30, 0.5f);
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &shape;
		fixtureDef.density = 1.2f;
		lbox->CreateFixture(&fixtureDef);

		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(-3, 10);
		b2Body* ubox = m_world->CreateBody(&bodyDef);
		dbody = m_world->CreateBody(&bodyDef);
		shape.SetAsBox(2, 2);
		fixtureDef.shape = &shape;
		ubox->CreateFixture(&fixtureDef);
		dbody->CreateFixture(&fixtureDef);
		ubox->SetTransform(b2Vec2(10, 20), 45* DEGTORAD);
		ubox->SetLinearVelocity(b2Vec2(-5, 5));
		ubox->SetAngularVelocity(-90 * DEGTORAD);

		bodyDef.type = b2_kinematicBody;
		bodyDef.position.Set(-18, 11);
		b2Body* kbody = m_world->CreateBody(&bodyDef);
		kbody->CreateFixture(&fixtureDef);
		kbody->SetLinearVelocity(b2Vec2(1, 0));
		kbody->SetAngularVelocity(360 * DEGTORAD);



	} //do nothing, no scene yet



	void Step(Settings* settings)
	{

		//run the default physics and rendering
		Test::Step(settings);

		b2Vec2 position = dbody->GetPosition();
		float angle = dbody->GetAngle();
		b2Vec2 velocity = dbody->GetLinearVelocity();
		float angularVelocity = dbody->GetAngularVelocity();


		//show some text in the main screen
		g_debugDraw.DrawString(5, m_textLine, "Lines");
		m_textLine += DRAW_STRING_NEW_LINE;


		g_debugDraw.DrawString(5, m_textLine, "Position:  %.3f, %.3f Angle:%.3f", position.x, position.y, angle* RADTODEG);
		m_textLine += DRAW_STRING_NEW_LINE;
		g_debugDraw.DrawString(5, m_textLine, "Velocity: %.3f, %.3f Angular Velocity: %.3f", velocity.x, velocity.y, angularVelocity*RADTODEG);
		m_textLine += DRAW_STRING_NEW_LINE;
	}

	static Test* Create()
	{
		return new DrawTest;
	}
};

#endif