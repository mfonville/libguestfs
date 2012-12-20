/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2012 Red Hat Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <config.h>

#include "guestfs-gobject.h"

/**
 * SECTION:optargs-tar_out
 * @short_description: An object encapsulating optional arguments for guestfs_session_tar_out
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_tar_out
 */

#include <string.h>

#define GUESTFS_TAR_OUT_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_TAR_OUT, GuestfsTarOutPrivate))

struct _GuestfsTarOutPrivate {
  gchar *compress;
  GuestfsTristate numericowner;
  /* OStringList not implemented yet */
};

G_DEFINE_TYPE(GuestfsTarOut, guestfs_tar_out, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_TAR_OUT_PROP0,
  PROP_GUESTFS_TAR_OUT_COMPRESS,
  PROP_GUESTFS_TAR_OUT_NUMERICOWNER,
  PROP_GUESTFS_TAR_OUT_EXCLUDES
};

static void
guestfs_tar_out_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsTarOut *self = GUESTFS_TAR_OUT(object);
  GuestfsTarOutPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_TAR_OUT_COMPRESS:
      g_free(priv->compress);
      priv->compress = g_value_dup_string (value);
      break;

    case PROP_GUESTFS_TAR_OUT_NUMERICOWNER:
      priv->numericowner = g_value_get_enum (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_tar_out_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsTarOut *self = GUESTFS_TAR_OUT(object);
  GuestfsTarOutPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_TAR_OUT_COMPRESS:
      g_value_set_string(value, priv->compress);
      break;

    case PROP_GUESTFS_TAR_OUT_NUMERICOWNER:
      g_value_set_enum(value, priv->numericowner);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_tar_out_finalize(GObject *object)
{
  GuestfsTarOut *self = GUESTFS_TAR_OUT(object);
  GuestfsTarOutPrivate *priv = self->priv;

  g_free(priv->compress);

  G_OBJECT_CLASS(guestfs_tar_out_parent_class)->finalize(object);
}

static void
guestfs_tar_out_class_init(GuestfsTarOutClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  object_class->set_property = guestfs_tar_out_set_property;
  object_class->get_property = guestfs_tar_out_get_property;

  /**
   * GuestfsTarOut:compress:
   *
   * A string.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_TAR_OUT_COMPRESS,
    g_param_spec_string(
      "compress",
      "compress",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsTarOut:numericowner:
   *
   * A boolean.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_TAR_OUT_NUMERICOWNER,
    g_param_spec_enum(
      "numericowner",
      "numericowner",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_tar_out_finalize;
  g_type_class_add_private(klass, sizeof(GuestfsTarOutPrivate));
}

static void
guestfs_tar_out_init(GuestfsTarOut *o)
{
  o->priv = GUESTFS_TAR_OUT_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof(GuestfsTarOutPrivate));
}

/**
 * guestfs_tar_out_new:
 *
 * Create a new GuestfsTarOut object
 *
 * Returns: (transfer full): a new GuestfsTarOut object
 */
GuestfsTarOut *
guestfs_tar_out_new(void)
{
  return GUESTFS_TAR_OUT(g_object_new(GUESTFS_TYPE_TAR_OUT, NULL));
}
