template<class _ty>
class Collection
{
public:
    using value_type = _ty;
    using const_value_type = const value_type;
    using iterator = value_type*;
    using const_iterator = const value_type*;
    using reference = value_type&;
    using const_reference =  const value_type&;
    
    reference front() = 0; 
    const_reference front() = 0; 

    reference back() = 0; 
    const_reference back() = 0; 

    void push_front(const_reference p_elem) = 0; 
    void push_back(const_reference p_elem) = 0; 
    
    reference pop_front() = 0; 
    const_reference pop_front() = 0; 
    
    reference pop_back() = 0; 
    const_reference pop_back() = 0; 

private:
   


};
