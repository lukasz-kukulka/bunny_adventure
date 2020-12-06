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

void Single_pick_bonus::animation_ini(sf::Vector2f player_mid_pos)
{
	//std::cout << "tak" << std::endl;
	if (animation_delete_start == true && animation_finish == false)
	{
		this->bonus_sprite.setScale(sf::Vector2f(bonus_sprite.getScale().x + 0.1, 1));

		if (bonus_sprite.getScale().x > 3)
		{
			//std::cout << "single bonus ------ " << bonus_sprite.getPosition().x << std::endl;
			animation_finish = true;
			animation_delete_start = false;
		}
	}
}

bool Single_pick_bonus::animation_finish_out()
{
	return animation_finish;
}

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
}
