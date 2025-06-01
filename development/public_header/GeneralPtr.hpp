#include <iostream>

template<typename PointerType>
class GenericPointer {
private:

    PointerType * m_GenericPointer;



public:

    GenericPointer():m_GenericPointer(nullptr) {

    }

    GenericPointer(PointerType* p): m_GenericPointer(p) {}

    GenericPointer (const GenericPointer& otherGenericPointer) = delete;

    GenericPointer (GenericPointer&& otherGenericPointer) noexcept {
        m_GenericPointer = otherGenericPointer.m_GenericPointer;
        otherGenericPointer. m_GenericPointer= nullptr;
    }

    GenericPointer& operator=( const GenericPointer& otherGenericPointer) = delete;

    GenericPointer& operator=(GenericPointer&& otherGenericPointer) noexcept {
        if(this != &otherGenericPointer) {
            delete m_GenericPointer;
            m_GenericPointer = otherGenericPointer.m_GenericPointer;
            otherGenericPointer.m_GenericPointer = nullptr;
        }

        return *this;
    }


    ~GenericPointer() {
        delete m_GenericPointer;
    }

    PointerType* operator->() const {
        return m_GenericPointer;
    }

    PointerType& operator*() const {
        return *m_GenericPointer;
    }

};

