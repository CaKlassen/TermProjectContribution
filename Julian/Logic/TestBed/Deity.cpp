/*----------------------------------------------------------------------------------------------------------------------
-- class: Deity extends Entity
--
-- DATE: March 21, 2015
--
-- REVISIONS:
--
-- DESIGNER: Julian Brandrick
--
-- PROGRAMMER: Julian Brandrick
--
-- INTERFACE: class Deity : public Marx::Entity
--
-- NOTES:
--
--  Deity.cpp and Deity.h are deprecated and are not used in the program.
--
----------------------------------------------------------------------------------------------------------------------*/
#include "Deity.h"
#include "../Event.h"

#include <iostream>

/*----------------------------------------------------------------------------------------------------------------------
-- FUNCTION: Deity::Deity
--
-- DATE: March 21, 2015
--
-- REVISIONS:
--
-- DESIGNER: Julian Brandrick
--
-- PROGRAMMER: Julian Brandrick
--
-- INTERFACE: Deity::Deity(Marx::Map * gmap, float x, float y, Marx::Controller* controller, AbilityId one, AbilityId two)
--
-- PARAMETERS:
--      gmap       -> The gamemap of the client
--      x          -> The starting x coordinate of the deity
--      y          -> The starting y coordinate of the deity
--      controller -> The controller for the client
--      one        -> The first ability id
--      two        -> The second ability id
--
-- NOTES:
--  The constructor for the Deity class, handles initialization of class variables.
----------------------------------------------------------------------------------------------------------------------*/
Deity::Deity(Marx::Map * gmap, float x, float y, Marx::Controller* controller, AbilityId one, AbilityId two)
    : Max::Entity(gmap, x, y, controller)
{
    abilityMan = AbilityManager::getInstance(gmap);
    oneId = one;
    twoId = two;

    std::cout << "Deity constructed successfully" << std::endl;
}

/*----------------------------------------------------------------------------------------------------------------------
-- FUNCTION: Deity::onUpdate
--
-- DATE: March 21, 2015
--
-- REVISIONS:
--
-- DESIGNER: Julian Brandrick
--
-- PROGRAMMER: Julian Brandrick
--
-- INTERFACE: void Deity::onUpdate()
--
-- RETURNS: void
--
-- NOTES:
--  Catches all messages sent from the server.
----------------------------------------------------------------------------------------------------------------------*/
void Deity::onUpdate()
{
    std::vector<Marx::Event*> *eventQueue = getController()->getEvents();
    for(std::vector< Marx::Event*>::iterator it = eventQueue->begin(); it != eventQueue->end(); it++)
	{
		// switch on type
        switch((*it)->type)
		{
			case ::Marx::SKILL:
            SkillEvent* ev = (SkillEvent*) (*it);
            ev->getX();
            ev->getY();

            id_resource img;

            switch(ev->getType())
            {
                case HEAL:
                    img = ...;
                break;
                case HURT:
                    img = ...;
                break;
                case BUFF:
                    img = ...;
                break;
                case DEBUFF:
                    img = ...;
                break;
            }

            SGO*  = ....

            //Add to gamescene vector of skill assets with duration of skill

            break;
		}

	}
	getController()->clearEvents();
}
