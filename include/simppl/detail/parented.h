#ifndef SIMPPL_DETAIL_PARENTED_H
#define SIMPPL_DETAIL_PARENTED_H


#include <cassert>


struct Parented
{
   friend struct StubBase;
   friend struct Dispatcher;
   
protected:
 
   inline
   Parented()
    : parent_(0)
   {
      // NOOP
   }
   
   inline
   void reparent(void* parent)
   {
      assert(parent_);
      parent_ = parent;
   }
   
   template<typename ParentT>
   inline
   ParentT* parent()
   {
      assert(parent_);
      return (ParentT*)parent_;
   }
   
   inline
   ~Parented()
   {
      // NOOP
   }
   
   void* parent_;
};


#endif   // SIMPPL_DETAIL_PARENTED_H