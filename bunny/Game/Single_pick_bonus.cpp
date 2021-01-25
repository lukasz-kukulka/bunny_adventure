#include "Single_pick_bonus.hpp"

Single_pick_bonus::Single_pick_bonus(sf::RenderWindow& window, sf::Texture* texture, uint8_t type_of_item)
{
	//sprite_tex = texture;
	this->bonus_sprite.setTexture(*texture);
	//this->bonus_sprite.setScale(1.0 / (*tex).getSize().x * 100, 1.0 / (*tex).getSize().x * 100);
	this->bonus_sprite.setPosition(sf::Vector2f(-1000, -1500));
	//std::cout << "BONUS CREATE" << std::endl;
	this->delete_item = false;
	this->animation_finish = false;
	this->animation_delete_start = false;
	this->type_item = type_of_item;
	//sprite_tex = texture;
	//this->font.loadFromFile("Game/Fonts/beachday.ttf");
	//this->bonus_extra_efect_ini(window);
}

Single_pick_bonus::~Single_pick_bonus()
{

}

void Single_pick_bonus::changing_bonus_position(sf::Vector2f position)
{
	bonus_sprite.setPosition(sf::Vector2f(position.x, position.y));
}

sf::Vector2f Single_pick_bonus::position_out()
{
	return sf::Vector2f(bonus_sprite.getPosition().x, bonus_sprite.getPosition().y);
}

sf::Vector2f Single_pick_bonus::globalbound_out()
{
	return sf::Vector2f(bonus_sprite.getGlobalBounds().width, bonus_sprite.getGlobalBounds().height);
}

sf::Sprite Single_pick_bonus::bonus_out()
{
	return bonus_sprite;
}

bool Single_pick_bonus::if_can_you_delete_item()
{
	return delete_item;
}

void Single_pick_bonus::animation_delete()
{
	this->animation_delete_start = true;
	//std::cout << "dupa" << std::endl;
}


void Single_pick_bonus::animation_ini(sf::RenderWindow& window, sf::Sprite* player)
{
	//std::cout << "tak" << std::endl;
	
	
	if (animation_delete_start == true) // && animation_finish == false
	{
		//if (initialize_bonus_efect == true && bonus_extra_text[0].system(window) == 1)
		//{
		//	bonus_extra_text[0].system(window);
		//}
		//else
		//{
		//	this->initialize_bonus_efect = false;
		//	//bonus_extra_text.erase(0);
		//}
		if (animation_steps == 0)
		{

			if (animation_x_finished == false)
			{
				distanse_between_player_and_bonus_x = (player->getPosition().x + player->getGlobalBounds().width / 2) - (bonus_sprite.getPosition().x + bonus_sprite.getGlobalBounds().width / 2);
			}

			if (distanse_between_player_and_bonus_x <= movement_bonus_x && distanse_between_player_and_bonus_x >= (0 - movement_bonus_x))
			{
				bonus_sprite.setPosition(player->getPosition().x + player->getGlobalBounds().width / 2 - bonus_sprite.getGlobalBounds().width / 2, bonus_sprite.getPosition().y);
				distanse_between_player_and_bonus_x = 0;
				animation_x_finished = true;
			}
			else if (distanse_between_player_and_bonus_x >= movement_bonus_x)
			{
				bonus_sprite.setPosition(bonus_sprite.getPosition().x + movement_bonus_x, bonus_sprite.getPosition().y);
			}
			else if (distanse_between_player_and_bonus_x <  0 - movement_bonus_x)
			{
				bonus_sprite.setPosition(bonus_sprite.getPosition().x - movement_bonus_x, bonus_sprite.getPosition().y);
			}

			if (animation_y_finished == false)
			{
				distanse_between_player_and_bonus_y = -1 * player->getPosition().y - bonus_sprite.getPosition().y + bonus_sprite.getGlobalBounds().height;
			}
			if (distanse_between_player_and_bonus_y <= movement_bonus_y && distanse_between_player_and_bonus_y >= (0 - movement_bonus_y))
			{
				bonus_sprite.setPosition(bonus_sprite.getPosition().x, player->getPosition().y - bonus_sprite.getGlobalBounds().height);
				this->distanse_between_player_and_bonus_y = 0;
				animation_y_finished = true;
			}
			else if (distanse_between_player_and_bonus_y >= movement_bonus_y)
			{
				bonus_sprite.setPosition(bonus_sprite.getPosition().x, bonus_sprite.getPosition().y + movement_bonus_y);
			}
			else if (distanse_between_player_and_bonus_y < 0 - movement_bonus_y)
			{
				bonus_sprite.setPosition(bonus_sprite.getPosition().x, bonus_sprite.getPosition().y - movement_bonus_y);
			}

			if (distanse_between_player_and_bonus_x == 0 && distanse_between_player_and_bonus_y == 0)
			{
				animation_steps = 1;
			}
		}
		if (animation_steps == 1)
		{
			this->bonus_sprite.setScale(sf::Vector2f(bonus_sprite.getScale().x - 0.01, bonus_sprite.getScale().y - 0.01));
			if (bonus_sprite.getScale().x <= 0.02)
			{
				animation_steps = 2;
			}
		}

		if (animation_steps == 2)
		{
			animation_finish = true;
			animation_delete_start = false;
		}
		
	}
	
}

bool Single_pick_bonus::animation_finish_out()
{
	return animation_finish;
}

void Single_pick_bonus::delete_item_confirm()
{
	this->delete_item = true;
}

//void Single_pick_bonus::bonus_extra_efect_ini(sf::RenderWindow& window)
//{
//	
//}

uint8_t Single_pick_bonus::type_item_out()
{
	return type_item;
}

//sf::Texture Single_pick_bonus::texture_out()
//{
//	//sprite_tex = bonus_sprite.getTexture();
//	return bonus_sprite.getTexture();
//}

void Single_pick_bonus::draw(sf::RenderWindow& window)
{
	window.draw(bonus_sprite);
	//for (int i = 0; i < bonus_extra_text.size(); i++)
	//{
	//	bonus_extra_text[i].draw(window);
	//}
		
}
