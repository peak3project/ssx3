// The <exception>/<typeinfo> classes that exception.cc throws (seg/seg_313800_exception.cpp).
//
// libstdc++-v2's headers were compiled under `#pragma interface`: their inline destructors are inlined into the
// throw expressions here, while the out-of-line copies and the vtables are emitted by another object (tinfo.cc,
// seg/seg_315B68_tinfo). Declaring the classes the same way makes this unit only reference them, as retail does.
// Which class is which comes from the RTTI: the vtables' type_info functions name "9exception", "8bad_cast" and
// "10bad_typeid".
#pragma interface

class exception {
public:
    exception() {}
    virtual ~exception() {}
    virtual const char* what() const;
};

class bad_cast : public exception {
public:
    bad_cast() {}
    virtual ~bad_cast() {}
};

class bad_typeid : public exception {
public:
    bad_typeid() {}
    virtual ~bad_typeid() {}
};
