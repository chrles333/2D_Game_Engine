#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID() {
	static ComponentID lastID = 0;
	return lastID++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept {
	// Generate new lastID
	static ComponentID typeID = getComponentTypeID();
	return typeID;
}

// Tell if an entity has a component attached
constexpr std::size_t maxComponents = 32;

// Check if entity has got a selection of components
using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component {
public:
	Entity *entity;

	virtual void init() {}
	virtual void update() {}
	virtual void draw() {}
	
	virtual ~Component() {}
};


/*
 * Keeps a list of components
 */
class Entity {
private:
	// Keep track if entity is active
	bool active = true;

	// Keep list of all components the entity is holding
	std::vector<std::unique_ptr<Component>> components;

	ComponentArray componentArray;
	ComponentBitSet componentBitSet;

public:
	// Loop through entity's components and call update and draw method
	void update() {
		for (auto& c : components) c->update();
		for (auto& c : components) c->draw();
	}

	void draw() {}
	bool isActive() const { return active; }
	void destroy() { active = false; } // Can call entity's destroy function from a component

	// Check in bitset if entity has specific component attached
	template <typename T> bool hasComponent() const {
		return componentBitSet[getComponentID<T>()];
	}

	// Add component to entity
	template <typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs) {
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this;
		std::unique_ptr<Component> uPtr{ c };
		components.emplace_back(std::move(uPtr));

		// Components types have their specific index
		// Add component
		componentArray[getComponentTypeID<T>()] = c;
		componentBitSet[getComponentTypeID<T>()] = true;

		c->init();
		return *c;
	}

	// Can now get components using the component system like:
	// gameobject.getComponent<PositionComponent>().setXpos(val);
	template <typename T> T& getComponent() const {
		auto ptr(componentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}
};

/*
 * Keeps a list of entities
 */
class Manager {
private:
	// List of entities
	std::vector<std::unique_ptr<Entity>> entities;

public:
	// Update all existing entities
	void update() {
		for (auto& e : entities) e->update();
	}

	void draw() {
		for (auto& e : entities) e->draw();
	}

	// Remove non existant entities each frame
	void refresh() {
		entities.erase(std::remove_if(std::begin(entities), std::end(entities),
			[](const std::unique_ptr<Entity>& mEntity) {
				return !mEntity->isActive();
			}),
			std::end(entities));
	}

	// Add entity to the world
	Entity& addEntity() {
		Entity* e = new Entity();
		std::unique_ptr<Entity> uPtr{ e };
		
		// Add entity to entity list
		entities.emplace_back(std::move(uPtr));
		return *e;
	}
};