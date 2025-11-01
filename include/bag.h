/**
 * @file bag.h
 * @brief Bag ADT interface
 * @author Alena Voronchikhina
 * @date October 2025
 * 
 * @copyright Copyright (c) 2025
 */
#ifndef BAG_H
#define BAG_H

/**
 * @class Bag
 * @brief An unordered collection of items
 * @tparam T The type of elements in the bag
 */
template <typename T>
class Bag {
    public:
        /** @brief Virtual destructor to enable proper cleanup of derived classes */
        virtual ~Bag() = default;

        /**
         * @brief Adds an item to the bag
         * @param item The item to add
         */
        virtual void add(const T& item) = 0;

        /**
         * @brief Removes an item from the bag
         * @param item The item to remove
         * @return true if item was found and removed, false otherwise
         */
        virtual bool remove(const T& item) = 0;

        /**
         * @brief Gets the current number of items in the bag
         * @return The number of items in the bag
         */
        virtual int size() const = 0;

        /**
         * @brief Checks if the bag has no items
         * @return true if the bag is empty, false otherwise
         */
        virtual bool isEmpty() const = 0;

        /**
         * @brief Checks if an item exists in the bag
         * @param item The item to find
         * @return true if the item was found, false otherwise
         */
        virtual bool contains(const T& item) const = 0;
};

#endif  // BAG_H