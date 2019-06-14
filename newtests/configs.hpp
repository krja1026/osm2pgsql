#ifndef __OSM2PGSQL_TESTS_MIDDLE_CONFIG_HPP
#define __OSM2PGSQL_TESTS_MIDDLE_CONFIG_HPP

#include "common-pg.hpp"

#include "options.hpp"

// Various options settings to run the tests against.
namespace testing {
namespace options {

struct slim_default : options_t
{
    slim_default(pg::tempdb_t const &db)
    {
        database_options = db.db_options();
        prefix = "osm2pgsql_test";
        slim = true;
        cache = 1;
        num_procs = 1;
    }
};

struct slim_dense_cache : slim_default
{
    slim_dense_cache(pg::tempdb_t const &db) : slim_default(db)
    {
        alloc_chunkwise = ALLOC_DENSE;
    }
};

struct gazetteer_default : options_t
{
    gazetteer_default(pg::tempdb_t const &db)
    {
        database_options = db.db_options();
        output_backend = "gazetteer";
        style = "newtests/gazetteer-test.style";
    }

};

}
}

#endif // __OSM2PGSQL_TESTS_MIDDLE_CONFIG_HPP
