#pragma once
#include <iostream>
#include <string>
#include <map>

template <class Base, typename IdType>
class AbstractCreator {
public:
	virtual ~AbstractCreator() {}
	virtual Base* create(const IdType &id) const = 0;
};

template <class ObjectClass, class Base, typename IdType>
class Creator : public AbstractCreator <Base, IdType> {
public:
	Creator(IdType id) {}
	virtual ~Creator() {}
	Base* create(const IdType &id) const {
		return dynamic_cast<Base*>(new ObjectClass(id));
	}
};

template <class Base, class IdType>
class ObjectFactory {
protected:
	typedef AbstractCreator<Base, IdType> AbstractFactory;
	typedef std::map<IdType, AbstractFactory*> FactoryMap;
	FactoryMap factory_;

public:
	ObjectFactory() {}
	virtual ~ObjectFactory() {
		for (auto& item : factory_)
			delete item.second;
	}

	template <class C, typename idCreator>
	void add(const IdType &id) {
		registerClass(id, new Creator<C, Base, idCreator>(id));
	}

	template <typename idCreator>
	Base* create(const IdType &idClass, const idCreator &id) {
		return factory_[idClass]->create(id);
	}

protected:
	void registerClass(const IdType &id, AbstractFactory *ConcreteFabric) {
		typename FactoryMap::iterator it = factory_.find(id);
		if (it == factory_.end())
			factory_[id] = ConcreteFabric;
		else
			delete ConcreteFabric;
	}
};