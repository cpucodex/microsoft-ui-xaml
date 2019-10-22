﻿// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#pragma once

#include "NavigationViewItemBase.g.h"
#include "NavigationViewHelper.h"
#include "NavigationViewItemBase.properties.h"

class NavigationViewItemBase :
    public ReferenceTracker<NavigationViewItemBase, winrt::implementation::NavigationViewItemBaseT, winrt::composable>,
    public NavigationViewItemBaseProperties
{
public:

    // Promote all overrides that our derived classes want into virtual so that our shim will call them.
    // IFrameworkElementOverrides
    virtual void OnApplyTemplate()
    {
        __super::OnApplyTemplate();
    }

    // IUIElementOverrides
    virtual winrt::AutomationPeer OnCreateAutomationPeer()
    {
        return __super::OnCreateAutomationPeer();
    }

    virtual void OnPointerReleased(winrt::PointerRoutedEventArgs const& args) {
        __super::OnPointerReleased(args);
    };

    // IContentControlOverrides
    virtual void OnContentChanged(winrt::IInspectable const& oldContent, winrt::IInspectable const& newContent)
    {
        __super::OnContentChanged(oldContent, newContent);
    }

    // IControlOverrides overrides
    virtual void OnGotFocus(winrt::RoutedEventArgs const& e)
    {
        __super::OnGotFocus(e);
    }

    virtual void OnLostFocus(winrt::RoutedEventArgs const& e)
    {
        __super::OnLostFocus(e);
    }

    virtual void OnNavigationViewListPositionChanged() {}

    NavigationViewListPosition Position();
    void Position(NavigationViewListPosition value);
    
    winrt::NavigationView GetNavigationView();
    winrt::SplitView GetSplitView();
    winrt::NavigationViewList GetNavigationViewList();

    void OnRepeatedIndexPropertyChanged(const winrt::DependencyPropertyChangedEventArgs& args);
    void OnSelectionModelPropertyChanged(const winrt::DependencyPropertyChangedEventArgs& args);

    void SetNavigationViewParent(winrt::NavigationView const& navigationView);

protected:
    winrt::IndexPath GetIndexPath();
    bool IsRootItemsRepeater(winrt::hstring name);

private:
    NavigationViewListPosition m_position{ NavigationViewListPosition::LeftNav };

    bool IsRealized(winrt::IndexPath indexPath);
    void OnSelectionChanged(winrt::SelectionModel selectionModel, winrt::SelectionModelSelectionChangedEventArgs e);

    // Event Tokens
    winrt::SelectionModel::SelectionChanged_revoker m_selectionChangedEventToken{};

    winrt::weak_ref<winrt::NavigationView> m_navigationView{ nullptr };
};
