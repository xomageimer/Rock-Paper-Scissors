#ifndef pch
#define pch
#include "pch.h"
#endif

#ifndef PRS
#define PRS

struct prs {
	sf::Texture texture;
	virtual ~prs() = default;
};

struct scissors;
struct rock : prs
{
	sf::Sprite sprite;
	rock() : prs() {
		if (!texture.loadFromFile("rock.png"))
			throw;
		sprite.setTexture(texture);
	}
	bool beat(scissors & s) {
		return 1;
	}
	template <class T>
	bool beat(T & ) {
		return 0;
	};
};

struct paper : prs
{
	sf::Sprite sprite;
	paper() : prs() {
		if (!texture.loadFromFile("paper.png"))
			throw;
		sprite.setTexture(texture);
	}
	bool beat(rock & r) {
		return 1;
	}
	template <class T>
	bool beat(T &) {
		return 0;
	};
};

struct scissors : prs
{
	sf::Sprite sprite;
	scissors() : prs() {
		if (!texture.loadFromFile("scissors.png"))
			throw;
		sprite.setTexture(texture);
	}
	bool beat(paper & p) {
		return 1;
	}
	template <class T>
	bool beat(T &) {
		return 0;
	};
};


#endif  

