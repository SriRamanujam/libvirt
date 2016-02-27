/*
 * virsecretobj.h: internal <secret> objects handling
 *
 * Copyright (C) 2009-2010, 2013-2014, 2016 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#ifndef __VIRSECRETOBJ_H__
# define __VIRSECRETOBJ_H__

# include "internal.h"

# include "secret_conf.h"

typedef struct _virSecretObj virSecretObj;
typedef virSecretObj *virSecretObjPtr;
struct _virSecretObj {
    virSecretObjPtr next;
    char *configFile;
    char *base64File;
    virSecretDefPtr def;
    unsigned char *value;       /* May be NULL */
    size_t value_size;
};


virSecretObjPtr virSecretObjNew(void);

void virSecretObjEndAPI(virSecretObjPtr *secret);

typedef struct _virSecretObjList virSecretObjList;
typedef virSecretObjList *virSecretObjListPtr;

virSecretObjListPtr virSecretObjListNew(void);

#endif /* __VIRSECRETOBJ_H__ */