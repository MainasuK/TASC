/*
 * File: gcalloc.h
 * Version: 1.0
 * Last modified on Sat Aug 28 10:17:26 1993 by eroberts
 * -----------------------------------------------------
 * This file defines the interface for a garbage-collecting
 * allocator.  This interface defines only an initialization
 * function (InitGCAllocator) and facilities for protecting
 * global variables.  The actual allocation is handled by
 * the standard GetBlock and FreeBlock functions defined in
 * genlib.h.  These functions use the garbage-collecting
 * allocator if InitGCAllocator has been called.
 */

#ifndef _gcalloc_h
#define _gcalloc_h

#include <stdlib.h>
#include "genlib.h"

/*
 * Background
 * ----------
 * In a typical application program, memory is allocated in
 * three different regions.  Static data is stored in fixed
 * memory addresses and is declared in C using the storage
 * classes static or extern (extern is in fact omitted in
 * the defining instance).  Automatic data (the default
 * storage class for variables defined within a function)
 * is stored on the control stack, where it is allocated
 * when a function is called and deallocated on return
 * from that function.  In addition to these two classes,
 * however, many programs will need to allocated additional
 * memory from an expandable pool called the "heap."  All
 * memory in the heap is addressed via pointers, which are
 * generated as the program runs.
 *
 * Although heap allocation is extremely convenient,
 * particularly when used in library implementations, it
 * suffers from an important failing.  The problem is not
 * identifying what parts of the program have responsibility
 * for allocating memory.  That task is easy.  The thorny
 * issue is who has responsibility for freeing previously
 * allocated memory when it is no longer needed.
 *
 * The central problem is that the operations of allocating
 * and freeing memory are most naturally situated on opposite
 * sides of the interface boundary between an implementation
 * and its client.  The implementation knows when to allocate
 * memory and simply returns pointers to the client.  The
 * implementation, however, has no idea when the client is
 * finished with the allocated object, so that freeing the
 * storage has to remain the client's responsibility, even
 * though the client may not understand enough about the
 * object's structure to do so.
 *
 * To get around this problem, most libraries have been
 * designed in one of two ways.  One approach is to make
 * the client responsible for allocating storage and
 * passing a pointer to the implementation.  The alternative
 * is to provide procedures in each interface that free any
 * storage allocated by the abstraction.  Each of these
 * approaches is decidedly non-optimal.
 *
 * A completely different alternative is to use a strategy
 * called "garbage collection."  Under this strategy,
 * implementations are free to allocate memory and pass
 * their addresses back to the client.  As long as the
 * client holds that pointer, the memory is considered
 * to be in use.  When the pointer goes away (which occurs
 * when a different pointer is assigned to the variable or
 * when the variable holding the pointer is deallocated
 * by returning from the function declaring it), the
 * storage to which it referred is no longer accessible,
 * and can be reallocated to new purposes.
 *
 * Detecting what memory is garbage does not happen as the
 * memory becomes inaccessible.  Instead, the traditional
 * garbage-collection strategy is to wait until a memory
 * cannot be satisfied, and then to go through accessible
 * memory to see what previously allocated blocks are no
 * longer reachable, freeing these for reuse.
 */

/*
 * Client responsibilities
 * -----------------------
 * The garbage-collecting allocator imposes some important
 * responsibilities on the client who uses the package.  In
 * particular, the client must agree to obey the following
 * rules:
 *
 *   (1)  Whenever a heap object is allocated, the client
 *        must agree to keep at least one copy of the
 *        original pointer returned by GetBlock.  In C,
 *        it is common to use pointer arithmetic to adjust
 *        a pointer so that, for example, it points to the
 *        interior of an array.  The rule is that a block
 *        is protected from garbage collection only by
 *        a pointer to its beginning and not to its
 *        interior.  Note that this rule does not prohibit
 *        pointing to the interior of the block; the
 *        implication is simply that the client must
 *        also keep the original pointer around.
 *
 *   (2)  The garbage collector must be able to identify
 *        all places in which valid heap pointers might
 *        be maintained, so that it can ensure that
 *        valid data is not collected by accident.  This
 *        package (subject to the system assumptions
 *        below) is able to find pointers living in
 *        automatic variables on the stack, or in heap
 *        blocks allocated by GetBlock which themselves
 *        remain accessible (see condition 3 as well).  If
 *        static variables contain allocated data, however,
 *        the client must warn the allocator of this
 *        fact by calling
 *
 *                ProtectVariable(variable);
 *
 *        where variable is the name of the global
 *        variable.
 *
 *   (3)  It is the client's responsibility to free
 *        explicitly any storage allocated outside of the
 *        GetBlock/FreeBlock mechanism.  Moreover, it is
 *        also important to remember that the garbage
 *        collector is not able to find pointers which are
 *        stored in dynamically allocated blocks unless
 *        those blocks were allocated by GetBlock.  Thus,
 *        if an implementation makes direct calls to the
 *        system allocation functions in addition to
 *        GetBlock, that implementation may not store the
 *        GetBlock pointers in the system-allocated memory.
 */

/*
 * Function: InitGCAllocator
 * Usage: InitGCAllocator(&argc);
 * ------------------------------
 * This call enables the garbage-collecting allocator and
 * also establishes the base of the stack for tracing.  This
 * call should be made from main, and the address passed
 * should be the address of the argc parameter.
 */

void InitGCAllocator(void *stackbase);

/*
 * Macro: ProtectVariable
 * Usage: ProtectVariable(v);
 * --------------------------
 * Registers a global variable with the allocation system, so
 * that the variable is traced when the garbage collector is
 * used.  This operation needs to be provided in "genlib.h"
 * so that code can be written to function correctly whether
 * or not the garbage-collecting allocator is loaded.
 */

#define ProtectVariable(v) ProtectBlock(&v, sizeof v)

/*
 * Function: ProtectBlock
 * Usage: ProtectBlock(ptr, nbytes);
 * ---------------------------------
 * This function is not usually called by clients (who will
 * ordinarily use ProtectVariable instead), but has the
 * effect of protecting the block of memory beginning at
 * ptr and extending for nbytes from the garbage collector.
 */

void ProtectBlock(void *ptr, size_t nbytes);

/*
 * Global linkage variable: _acb
 * -----------------------------
 * This variable is used to hold the allocation control block
 * that provides the linkage between this package and the
 * dynamic allocator.  The reason for using the structure
 * as a linkage is so that the garbage-collecting allocator
 * need not even be loaded if it is not explicitly called.
 */

typedef struct {
    void *(*allocMethod)(size_t nbytes);
    void (*freeMethod)(void *ptr);
    void (*protectMethod)(void *ptr, size_t nbytes);
} *_GCControlBlock;

extern _GCControlBlock _acb;

#endif
