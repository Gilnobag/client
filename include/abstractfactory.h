#pragma once
#include <iostream>
#include <string>
#include <map>

template <class Base, typename CreatorParam>
class AbstractCreator {
public:
	virtual ~AbstractCreator() {}
    virtual Base* create(const CreatorParam &id) const = 0;
};

template <class ObjectClass, class Base, typename CreatorParam>
class Creator : public AbstractCreator<Base, CreatorParam> {
public:
    Creator() {}
	virtual ~Creator() {}
    Base* create(const CreatorParam &params) const {
        return dynamic_cast<Base*>(new ObjectClass(params));
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

    template <class C, typename CreatorParam>
    void addClass(const IdType &id) {
        registerClass(id, new Creator<C, Base, CreatorParam>());
	}

    template <typename CreatorParam>
    Base* createObject(const IdType &idClass, const CreatorParam &parameters) {
        return factory_[idClass]->create(parameters);
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
