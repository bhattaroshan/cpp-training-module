
#include "let.h"


Let::Let(std::initializer_list<VariantType> initList):m_var(std::vector<VariantType>(initList)){}


Let Let::operator+(const Let &other){
   Let c;
   if (std::holds_alternative<VariantType>(m_var) && std::holds_alternative<VariantType>(other.m_var)) {
            std::visit([&](auto&& rval){
                std::visit([&](auto&& lval) {
                    if(typeid(rval)==typeid(int) && typeid(lval)==typeid(int)){
                        c.m_var = std::get<int>(std::get<VariantType>(m_var))+std::get<int>(std::get<VariantType>(other.m_var));
                    }else if(typeid(rval)==typeid(int) && typeid(lval)==typeid(double)){
                        c.m_var = (double)std::get<int>(std::get<VariantType>(other.m_var))+std::get<double>(std::get<VariantType>(m_var));
                    }else if(typeid(rval)==typeid(double) && typeid(lval)==typeid(int)){
                        c.m_var = std::get<double>(std::get<VariantType>(other.m_var))+(double)std::get<int>(std::get<VariantType>(m_var));
                    }else if(typeid(rval)==typeid(std::string) && typeid(lval)==typeid(std::string)){
                        c.m_var = std::get<std::string>(std::get<VariantType>(m_var))+std::get<std::string>(std::get<VariantType>(other.m_var));
                    }else if(typeid(rval)==typeid(double) && typeid(lval)==typeid(double)){
                        c.m_var = std::get<double>(std::get<VariantType>(other.m_var))+std::get<double>(std::get<VariantType>(m_var));
                    }
                }, std::get<VariantType>(m_var));
            },std::get<VariantType>(other.m_var));

    }else if(std::holds_alternative<std::vector<VariantType>>(m_var) && std::holds_alternative<std::vector<VariantType>>(other.m_var)){
        auto &vec = std::get<std::vector<VariantType>>(m_var);
        auto &vecOther = std::get<std::vector<VariantType>>(other.m_var);
        for(auto&& val:vecOther){
            std::visit([&](auto&& rval){
                vec.emplace_back(rval);
            },val);
        }
    }else{
        std::cout<<"Doesn't support normal datatype operation with list."<<std::endl;
    }
    return c;
}

char Let::operator[](const int index){
    char result = 0;
    if(std::holds_alternative<VariantType>(m_var)){
        std::visit([&](auto&& value){
            if(typeid(value)==typeid(std::string)){
                std::string res = std::get<std::string>(std::get<VariantType>(m_var));
                if(index<res.size()){
                    result = res[index];
                }else{
                    std::cout<<"array out of bound";
                }
            }else{
                std::cout<<"indexing support only available from strings.";
            }
        },std::get<VariantType>(m_var));
    }else{
        std::cout<<"indexing support not available for list.";
    }

    return result;
}

std::ostream& operator<<(std::ostream& os, Let &let){
    if(std::holds_alternative<VariantType>(let.m_var)){
        std::visit([&](auto&& val){
            os<<val;
        },std::get<VariantType>(let.m_var));
    }else if(std::holds_alternative<std::vector<VariantType>>(let.m_var)){
        auto& vec = std::get<std::vector<VariantType>>(let.m_var);
             for (auto&& val : vec) {
        std::visit([&](auto&& element) {
            os << element << " "; 
        }, val);
    }
    }
    return os;
}