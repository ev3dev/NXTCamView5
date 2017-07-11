/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/

#pragma once

#include "cvssettings.h"

#include <vcsbase/vcsbaseclient.h>

namespace Cvs {
namespace Internal {

class CvsSettings;

class CvsClient : public VcsBase::VcsBaseClient
{
    Q_OBJECT

public:
    CvsClient();

    CvsSettings &settings() const;
    void diff(const QString &workingDir, const QStringList &files,
              const QStringList &extraOptions = QStringList()) override;
    QString findTopLevelForFile(const QFileInfo &file) const override;
    QStringList revisionSpec(const QString &revision) const override;
    StatusItem parseStatusLine(const QString &line) const override;

protected:
    Utils::ExitCodeInterpreter *exitCodeInterpreter(VcsCommandTag cmd, QObject *parent) const override;
    Core::Id vcsEditorKind(VcsCommandTag cmd) const override;
};

} // namespace Internal
} // namespace Cvs