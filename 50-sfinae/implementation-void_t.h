#pragma once
#include<type_traits>

template<typename... Ts>
struct voider
{
    using type = void;
};

template<typename... Ts>
using void_t = typename voider<Ts...>::type;



template<typename T, typename = void>
struct has_type_typedef : std::false_type {
};

template<typename T>
struct has_type_typedef<T, void_t<typename T::type    >>  : std::true_type {
};

/*template<typename T, typename = void>
struct has_member_variable : std::false_type {
};

template<typename T>
struct has_member_variable<T, void_t<decltype(std::declval<T>().member)    >> : std::true_type {
};*/


template<typename T, typename = void>     //zrobilismy sobie alternatywna wersje ktora dodatkowo sprawdza czy member jest danego typu(int w  tym wypadku)
struct has_member_variable : std::false_type {
};

template<typename T>
struct has_member_variable<T,
void_t<
typename std::enable_if<//tu jak nie bylo typename to kompilator nie ogarnial
std::is_same<
int,                    // sprawdzasz czy typ int i typ z decltype() sa tego samego typu
decltype(std::declval<T>().member)
>::value//bo do enable_if potrzebujesz value
>::type//bo do void_t potrzebujesz typu
>> : std::true_type {// dziedziczysz po true_type
};

