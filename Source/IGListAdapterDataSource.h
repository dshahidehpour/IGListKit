/**
 * Copyright (c) 2016-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <UIKit/UIKit.h>

#import <IGListKit/IGListDiffable.h>

@class IGListAdapter;
@class IGListSectionController;

@protocol IGListSectionType;

NS_ASSUME_NONNULL_BEGIN

/**
 Implement this protocol to provide data to an `IGListAdapter`.
 */
@protocol IGListAdapterDataSource <NSObject>

/**
 Asks the data source for the objects to display in the list.

 @param listAdapter The list adapter requesting this information.

 @return An array of objects for the list.
 */
- (NSArray<id <IGListDiffable>> *)objectsForListAdapter:(IGListAdapter *)listAdapter;

/**
 Asks the data source for a section controller for the specified object in the list.

 @param listAdapter The list adapter requesting this information.
 @param object      An object in the list.

 @return A new section controller instance that can be displayed in the list.

 @note New section controllers should be initialized here for objects when asked. You may pass any other data to
 the section controller at this time.

 Section controllers are initialized for all objects whenever the `IGListAdapter` is created, updated, or reloaded.
 Section controllers are reused when objects are moved or updated. Maintaining the `-[IGListDiffable diffIdentifier]`
 guarentees this.
 */
- (IGListSectionController <IGListSectionType> *)listAdapter:(IGListAdapter *)listAdapter sectionControllerForObject:(id)object;

/**
 Asks the data source for a view to use as the collection view background when the list is empty.

 @param listAdapter The list adapter requesting this information.

 @return A view to use as the collection view background, or `nil` if you don't want a background view.

 @note This method is called every time the list adapter is updated. You are free to return new views every time,
 but for performance reasons you may want to retain the view and return it here. The infra is only responsible for
 adding the background view and maintaining its visibility.
 
 It is also worth mentioning that if `emptySectionControllerForListAdapter:` has been implemented, this will have no affect.
 */
- (nullable UIView *)emptyViewForListAdapter:(IGListAdapter *)listAdapter;

/**
 Asks the data source for a section controller to display a cell when there are no objects.

 @param listAdapter The list adapter requesting this information.

 @return A section controller that is responsible for a cell to display when there are no objects, or nil if you don't want to display anything.

 @discussion This method is called every time the list adapter is updated. You are free to return a new section controller every time,
 but for performance reasons you may want to retain your own section controller and return it here. This callback will supercede `emptyViewForListAdapter:`.
 */
- (nullable IGListSectionController <IGListSectionType> *)emptySectionControllerForListAdapter:(IGListAdapter *)listAdapter;

@end

NS_ASSUME_NONNULL_END
