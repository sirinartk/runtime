#ifndef _MONO_METADATA_LOADER_H_
#define _MONO_METADATA_LOADER_H_ 1

#include <mono/metadata/metadata.h>
#include <mono/metadata/image.h>

typedef struct {
	guint16 flags;  /* method flags */
	guint16 iflags; /* method implementation flags */
	MonoClass *klass;
	MonoMethodSignature *signature;
	gpointer addr;
	/* name is useful mostly for debugging */
	const char *name; 
} MonoMethod;

typedef struct {
	MonoMethod method;
	MonoMethodHeader *header;
} MonoMethodNormal;

typedef struct {
	MonoMethod method;
	guint16 piflags;  /* pinvoke flags */
	void  (*code) ();
} MonoMethodPInvoke;

typedef struct {
	MonoImage *corlib;
	MonoClass *object_class;
	MonoClass *byte_class;
	MonoClass *void_class;
	MonoClass *boolean_class;
	MonoClass *sbyte_class;
	MonoClass *int16_class;
	MonoClass *uint16_class;
	MonoClass *int32_class;
	MonoClass *uint32_class;
	MonoClass *int_class;
	MonoClass *uint_class;
	MonoClass *int64_class;
	MonoClass *uint64_class;
	MonoClass *single_class;
	MonoClass *double_class;
	MonoClass *char_class;
	MonoClass *string_class;
	MonoClass *enum_class;
	MonoClass *array_class;
	MonoClass *delegate_class;
} MonoDefaults;

extern MonoDefaults mono_defaults;

void
mono_init                  (void);

MonoMethod *
mono_get_method            (MonoImage *image, guint32 token, MonoClass *klass);

void               
mono_free_method           (MonoMethod *method);

MonoImage *
mono_load_image            (const char *fname, enum MonoImageOpenStatus *status);

void
mono_add_internal_call     (const char *name, gpointer method);

gpointer
mono_lookup_internal_call  (const char *name);

#endif
