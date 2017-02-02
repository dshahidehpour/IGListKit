// Copyright 2004-present Facebook. All Rights Reserved.

#import "IGTestEmptySectionController.h"

@interface IGEmptyCollectionViewCell : UICollectionViewCell
@end

@implementation IGEmptyCollectionViewCell
@end

@implementation IGTestEmptySectionController

#pragma mark - IGListSectionType

- (NSInteger)numberOfItems {
    return 1;
}

- (CGSize)sizeForItemAtIndex:(NSInteger)index {
    return CGSizeMake(self.collectionContext.containerSize.width, self.collectionContext.containerSize.height);
}

- (UICollectionViewCell *)cellForItemAtIndex:(NSInteger)index {
    IGEmptyCollectionViewCell *cell = [self.collectionContext dequeueReusableCellOfClass:[IGEmptyCollectionViewCell class]
                                                                    forSectionController:self
                                                                                 atIndex:index];
    return cell;
}

- (void)didUpdateToObject:(id)object {}

- (void)didSelectItemAtIndex:(NSInteger)index {}

@end
