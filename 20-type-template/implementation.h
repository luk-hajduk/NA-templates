/*#pragma once

#include<cstddef>
#include<utility>

template<typename T>
class container_wrapper{
public:
container_wrapper() = default;
container_wrapper(T arg) : value(std::move(arg)){   //:value(arg) - tu jest jedno kopiowanie za duzo
}
container_wrapper(const container_wrapper &) = default;//konstruktor kopiujacy
container_wrapper( container_wrapper &&) = default;//konstruktor przesuwajacy
container_wrapper & operator = (const container_wrapper &) = default;//operator  kopiujacy
container_wrapper & operator = ( container_wrapper &&) = default;//operator  przesuwajacy




std::size_t size() const{

return value.size();

}



private:
T value;


};
*/
#pragma once
#include<cstddef>
#include<utility>
#include<boost/optional.hpp>//dodalismy atego includa

template<typename T>
class container_wrapper{
public:
container_wrapper() = default;
container_wrapper(T arg) : value(std::move(arg)){   //:value(arg) - tu jest jedno kopiowanie za duzo
}
container_wrapper(const container_wrapper &) = default;//konstruktor kopiujacy
container_wrapper( container_wrapper &&) = default;//konstruktor przesuwajacy
container_wrapper & operator = (const container_wrapper &) = default;//operator  kopiujacy
container_wrapper & operator = ( container_wrapper &&) = default;//operator  przesuwajacy

std::size_t size() const{

return value.size();
}

private:

T value;


};

template<typename T>//to jest czesciowa specjalizacja o tu zostaje typename T
class container_wrapper<boost::optional<T>>{//wszedzie za T wstwiamy typ boost::optional<T>
public:
container_wrapper() = default;
container_wrapper(boost::optional<T> arg) : value(std::move(arg)){   //:value(arg) - tu jest jedno kopiowanie za duzo
}
container_wrapper(const container_wrapper &) = default;//konstruktor kopiujacy
container_wrapper( container_wrapper &&) = default;//konstruktor przesuwajacy
container_wrapper & operator = (const container_wrapper &) = default;//operator  kopiujacy
container_wrapper & operator = ( container_wrapper &&) = default;//operator  przesuwajacy


std::size_t size() const{

return value  ? 1 : 0;//tu poprawialismy
}

private:

boost::optional<T> value;

};
