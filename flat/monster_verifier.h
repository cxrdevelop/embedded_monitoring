#ifndef MONSTER_VERIFIER_H
#define MONSTER_VERIFIER_H

/* Generated by flatcc 0.6.1-dev FlatBuffers schema compiler for C by dvide.com */

#ifndef MONSTER_READER_H
#include "monster_reader.h"
#endif
#include "flatcc/flatcc_verifier.h"
#include "flatcc/flatcc_prologue.h"

static int GasBoil_Message_verify_table(flatcc_table_verifier_descriptor_t *td);

static int GasBoil_Message_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_field(td, 0, 1, 1) /* type */)) return ret;
    if ((ret = flatcc_verify_field(td, 1, 2, 2) /* ack */)) return ret;
    if ((ret = flatcc_verify_field(td, 2, 2, 2) /* dataSize */)) return ret;
    if ((ret = flatcc_verify_vector_field(td, 3, 0, 1, 1, INT64_C(4294967295)) /* data */)) return ret;
    return flatcc_verify_ok;
}

static inline int GasBoil_Message_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, GasBoil_Message_identifier, &GasBoil_Message_verify_table);
}

static inline int GasBoil_Message_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, GasBoil_Message_type_identifier, &GasBoil_Message_verify_table);
}

static inline int GasBoil_Message_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &GasBoil_Message_verify_table);
}

static inline int GasBoil_Message_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &GasBoil_Message_verify_table);
}

#include "flatcc/flatcc_epilogue.h"
#endif /* MONSTER_VERIFIER_H */
