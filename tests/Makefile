# Κάνοντας compile το <foo>_test.c με μια υλοποίηση <foo>.c του
# συγκεκριμένου τύπου, παράγουμε ένα tets για την υλοποίηση αυτή.

# Υλοποιήσεις μέσω Heap: ADTPriorityQueue
# Το Heap χρησιμοποιεί Vector, οπότε χρειαζόμαστε και μια υλοποίηση του ADTVector.
#
#UsingHeap_ADTPriorityQueue_test_OBJS  = ADTPriorityQueue_test.o $(MODULES)/UsingHeap/ADTPriorityQueue.o $(MODULES)/UsingDynamicArray/ADTVector.o

UsingLinkedTree_ADTRecTree_test_OBJS  = ADTRecTree.o $(MODULES)/UsingLinkedTree/ADTRecTree.o 
UsingADTMap_ADTRecTree_test_OBJS = ADTRecTree.o $(MODULES)/UsingADTMap/ADTRecTree.o $(MODULES)/ADTMap.o $(MODULES)/ADTSet.o

UsingADTLinkedTree_ADTRecTree_utils_test_OBJS = ADTRecTree_utils_test.o $(MODULES)/ADTRecTree_utils.o $(MODULES)/UsingLinkedTree/ADTRecTree.o
UsingADTMap_ADTRecTree_utils_test_OBJS = ADTRecTree_utils_test.o $(MODULES)/ADTRecTree_utils.o $(MODULES)/UsingADTMap/ADTRecTree.o $(MODULES)/ADTMap.o $(MODULES)/ADTSet.o


UsingADTRecTreeMap_ADTCompTree_test_OBJS = ADTCompTree.o $(MODULES)/UsingADTRecTree/ADTCompTree.o $(MODULES)/ADTMap.o $(MODULES)/ADTSet.o $(MODULES)/ADTRecTree_utils.o $(MODULES)/UsingADTMap/ADTRecTree.o
UsingADTRecTreeLinked_ADTCompTree_test_OBJS = ADTCompTree.o $(MODULES)/UsingADTRecTree/ADTCompTree.o $(MODULES)/UsingLinkedTree/ADTRecTree.o $(MODULES)/ADTRecTree_utils.o

UsingADTCompTreeLinked_ADTPriorityQueue_test_OBJS  = ADTPriorityQueue_test.o $(MODULES)/UsingADTCompTree/ADTPriorityQueue.o $(MODULES)/UsingDynamicArray/ADTVector.o $(MODULES)/UsingADTRecTree/ADTCompTree.o $(MODULES)/UsingLinkedTree/ADTRecTree.o $(MODULES)/ADTRecTree_utils.o
UsingADTCompTreeMap_ADTPriorityQueue_test_OBJS  = ADTPriorityQueue_test.o $(MODULES)/UsingADTCompTree/ADTPriorityQueue.o $(MODULES)/UsingDynamicArray/ADTVector.o $(MODULES)/UsingADTRecTree/ADTCompTree.o $(MODULES)/UsingADTMap/ADTRecTree.o $(MODULES)/ADTMap.o $(MODULES)/ADTSet.o $(MODULES)/ADTRecTree_utils.o

# Ο βασικός κορμός του Makefile
include ../common.mk