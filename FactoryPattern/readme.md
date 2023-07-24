### 设计思路
    1. 使用抽象工厂方式，将家具的生产，物流运输的方式来进行创建
    2. 由于家具工厂和物流工厂比较多，创建专门生产家具工厂的工厂的类、专门指定物流方式的方式类
    3. 物流内部维护unordered_map，通过工厂的名字生产不同类型的家具

### 优势
    1.创建了专门生产的家具工厂的类，和物流工厂的类，便于对家具厂进行扩展
    2.只需要创建家具生产厂，就可以在不修改代码的基础上，加入到家具生产厂
    3.只需要创建物流生产厂，就可以在不修改代码的基础上，加入到物流厂
 原因：
    LogisticsCreateFactory内部维护着一个unordered_map<string, Logistics*>
    FurnitureCreateFactory内部也维护着一个unordered_map<string,FurnitureFactory*>
    对于每次创建新的工厂，就可以放入到对应的unordered_map中，不需要进行代码的修改。

### 使用单例来创建物流的工厂类
    创建一个专门生产物流的类的单例 LogisticsCreateFactory ，LogisticsCreateFactory内部维护着一个unordered_map，每次有新的物流工厂的创建，都将新的物流工厂放入其中，CreateTransport方法更具物流的名称来创建对应的运输工具。
```
//Use Singleton Template 
class LogisticsCreateFactory:public Singleton<LogisticsCreateFactory>
{
	friend class Singleton<LogisticsCreateFactory>;
public:
	void AddTransportFactory(const string & logisticsname, Logistics* logisticsfactory);
	BaseTransport* CreateTransport(const string & logisticsname);

private:
	LogisticsCreateFactory() = default;
	unordered_map<string, Logistics*> LogisticsFactorys;
};

```
### 使用单例来创建家具生产厂的工厂类

```
class FurnitureCreateFactory:public Singleton<FurnitureCreateFactory>
{
public:

	void AddFurnitureFactory(const string& factoryname, FurnitureFactory* furnitureFactory);
	Chair* createChair(const string& factoryname);
	CoffeeTable* createCoffeeTable(const string& factoryname);
	Sofa* createSofa(const string& factoryname);

//private:
	FurnitureCreateFactory() = default;
	unordered_map<string,FurnitureFactory*> furnitureFactorys;
};
```
### 抽象的家具工厂FurnitureFactory
    每次具有新的工厂，则将自身加入到FurnitureCreateFactory中

```
class FurnitureFactory
{
public:
    virtual ~FurnitureFactory() {};

    FurnitureFactory(const string furnitureFactoryName) :_furnitrueFactoryName(furnitureFactoryName)
    {
        Singleton<FurnitureCreateFactory>::GetInstance().AddFurnitureFactory(furnitureFactoryName,this);
    }

public:
    virtual Chair* createChair() = 0;
    virtual CoffeeTable* createCoffeeTable() = 0;
    virtual Sofa* createSofa()= 0;
private:
    string _furnitrueFactoryName;
};
```


### 抽象的物流工厂Logistics
    每次具有新的物流工厂，则将自身加入到LogisticsCreateFactory中

```
class Logistics
{
public:
    virtual ~Logistics() {}
    virtual BaseTransport* CreateTransport() const = 0;

    Logistics(const string& logisticsName) :_LogisticsName(logisticsName)
    {
        LogisticsCreateFactory::GetInstance().AddTransportFactory(logisticsName,this);
    }
private:
    string _LogisticsName;
};
```

### 抽象的运输BaseTransport
    使用BaseTransport作为运输方式的基类，同时内部维护着unordered_map，用来存储家具的名字和数量。

```
class BaseTransport {
public:
    virtual ~BaseTransport() {}
    virtual string Deliver() const = 0;
	void addFurniture(BaseFurniture* Furniture);
	void showFurniture();

private:
	unordered_map<string, int> furnitures;
	BaseTransport* transports = nullptr;
};

```



### 单例的模板类

```
template<typename T>
class Singleton
{

public:
	static T& GetInstance()
	{
		static T* instance = new T();
		return *instance;
	}

protected:
	Singleton() {};
};

```