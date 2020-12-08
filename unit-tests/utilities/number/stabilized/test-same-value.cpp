// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2020 Intel Corporation. All Rights Reserved.

//#cmake:add-file ../../../../common/utilities/number/stabilized-value.h


#include "../../../test.h"
#include <../common/utilities/number/stabilized-value.h>

using namespace utilities::number;

// Test group description:
//       * This tests group verifies stabilized_value class.
//
// Current test description:
//       * Verify if history is full with a specific value, the stabilized value is always the same
//         no matter what percentage is required
TEST_CASE( "stable value sanity - 100%", "[stabilized value]" )
{
    try
    {
        stabilized_value< float > stab_value( 5 );
        CHECK_NOTHROW( stab_value.add( 1.0f ) );
        CHECK_NOTHROW( stab_value.add( 1.0f ) );
        CHECK_NOTHROW( stab_value.add( 1.0f ) );
        CHECK_NOTHROW( stab_value.add( 1.0f ) );
        CHECK_NOTHROW( stab_value.add( 1.0f ) );

        CHECK( 1.0f == stab_value.get( 1.0f ) );
    }
    catch( const std::exception & e )
    {
        FAIL( "Exception caught: " << e.what() );
    }
}

TEST_CASE( "stable value sanity - 40%", "[stabilized value]" )
{
    try
    {
        stabilized_value< float > stab_value( 5 );
        CHECK_NOTHROW( stab_value.add( 1.0f ) );
        CHECK_NOTHROW( stab_value.add( 1.0f ) );
        CHECK_NOTHROW( stab_value.add( 1.0f ) );
        CHECK_NOTHROW( stab_value.add( 1.0f ) );
        CHECK_NOTHROW( stab_value.add( 1.0f ) );

        CHECK( 1.0f == stab_value.get( 0.4f ) );
    }
    catch( const std::exception & e )
    {
        FAIL( "Exception caught: " << e.what() );
    }
}

TEST_CASE( "stable value sanity - 25%", "[stabilized value]" )
{
    try
    {
        stabilized_value< float > stab_value( 5 );
        CHECK_NOTHROW( stab_value.add( 1.0f ) );
        CHECK_NOTHROW( stab_value.add( 1.0f ) );
        CHECK_NOTHROW( stab_value.add( 1.0f ) );
        CHECK_NOTHROW( stab_value.add( 1.0f ) );
        CHECK_NOTHROW( stab_value.add( 1.0f ) );

        CHECK( 1.0f == stab_value.get( 0.25f ) );
    }
    catch( const std::exception & e )
    {
        FAIL( "Exception caught: " << e.what() );
    }
}
