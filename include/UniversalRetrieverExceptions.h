/**
 * @file UniversalRetrieverExceptions.h
 * 
 * @author Massimiliano Culpo
 *
 * Created on December 18, 2014, 8:58 PM
 */

#ifndef UNIVERSALRETRIEVEREXCEPTIONS_H_20141218
#define	UNIVERSALRETRIEVEREXCEPTIONS_H_20141218

#include <stdexcept>

namespace universal_retriever {

/**
 * @brief Exception thrown if an handler is not found in a query
 */
class HandlerNotFound : public std::out_of_range { 
  using std::out_of_range::out_of_range;
};

}

#endif	/* UNIVERSALRETRIEVEREXCEPTIONS_H_20141218 */

